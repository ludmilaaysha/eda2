# Introdução a grafos
## Conceitos iniciais
### O que são?
Um grafo é uma estrutura de dados composta por vértices e arestas, que ligam os vértices entre si

- Exemplos de grafos são:
	- Mapas, com pontos de decisão do mapa sendo vértices e ruas sendo as arestas
	- Redes sociais, como o instagram
	- Páginas web (hipertextos), com links para páginas externas ou dentro delas mesmas
	- Circuitos, em que há portas lógicas que se comunicam e fios que ligam essas portas
- Vértices são numerados de `0` a `v-1`

### Caminho
> Vértices em que cada vértice sucessivo é adjacente ao predecessor no caminho (RIBAS, 2020).

Ou seja, caminho é uma combinação de arestas possível para se chegar de um vértice a outro.
Existem alguns tipos de caminho, como
#### Caminho simples
Os vértices e arestas são distintos

#### Ciclo
Um ciclo é um caminho simples, com exceção do primeiro e último vértices, pois são os mesmos.

---
### Tipos de grafos
#### Grafo não dirigido
Vértices são ligados por arestas que não possuem direção única definida. É possível transitar entre dois vértices por uma mesma aresta sem preocupar-se com as possíveis direções.

![[Pasted image 20250601233657.png]]

#### Grafo dirigido
As arestas possuem direção única, ao contrário dos não dirigidos.
- É como se fosse uma via de mão única

![[Pasted image 20250601233902.png]]

#### Grafo completo
Todas as arestas se conectam entre si
- Em um grafo de v arestas, o máximo de arestas que um grafo completo pode ter é $\frac{v \left( v - 1 \right)}{2}$
![[Pasted image 20250601234220.png]]

#### Grafo conexo
É um grafo em que, para todo vértice, é possível chegar em todos os outros. Há, pelo menos, um caminho entre um vértice e outro.

#### Grafo não conexo
Um grafo não conexo é um conjunto de componentes conexos

#### Árvores
Árvore é um grafo conexo acíclico.
Um conjunto de árvores é chamado de floresta.

```ad-info
title: Árvores e grafos
As árvores se enquadram em um tipo de grafo: os **Grafos Dirigidos Acíclicos**. 
Assim, grafos generalizam árvores e é importante saber que toda árvore é um grafo, mas nem todo grafo é uma árvore.
```



## Estruturas e funções básicas
A seguir, estão os protótipos das estruturas e funções mais básicas do grafo.
#### Arestas
*Struct* que liga dois inteiros (dois vértices)
```c
typedef struct{
	int v; int w;
}Edge;
```

#### Função de criar arestas
Função que devolve a aresta construída
```c
Edge EDGE(int, int);
```

#### Estrutura de grafo
```c
typedef struct graph *Graph;
```

#### Função de inicializar um grafo
Passa a quantidade de vértices e devolve uma estrutura de grafo com capacidade de alocar essa quantidade de vértices.
```c
Graph GRAPHinit(int);
```

#### Inserir aresta no grafo
```c
void GRAPHInsertE(Graph, Edge);
```

#### Remover aresta do grafo
```c
void GRAPHRemoveE(Graph, Edge);
```

#### Contar arestas
Devolve quantas arestas tenho no grafo

```c
int GRAPHEdges(Edge[], Graph G];)
```

#### Copiar grafo
```c
Graph GRAPHCopy(Graph);
```

#### Destruir grafo
```c
void GRAPHDestroy(Graph);
```

---

## Formas de representar grafos
### Matriz de adjacências
Uma matriz que indica qual vértice está conectado com quem através do cruzamento entre linhas e colunas, as quais representam os vértices.
![[Pasted image 20250602003006.png]]

A ideia do código é receber a quantidade de vértices presente no grafo e inicializar um ponteiro para a struct do grafo. 
Depois, definir o V desse ponteiro, definir o E como 0 (inicia com 0 arestas) e criar uma matriz de adjacências $VxV$ com todas as adjacências como 0.
Essa função retorna o ponteiro para o grafo.
```c
struct graph{
	int V;
	int E;
	int **adj;
};

Graph GRAPHInit(int V){
	Graph G = malloc(sizeof(*G));
	G->V = V;
	G->E = 0;
	G->adj = MATRIXInit(V,V,0);
	return G;
}

void GRAPHInsertE(Graph G, Edge e){
	int v = e.v; w = e.w;
	if(G->adj[v][w] == 0){ // verifica se a aresta não existe ainda
		G->E++; // se não existir, incrementa a qtd de arestas do grafo
		G->adj[v][w] = 1; // define a conexão que representa a aresta como 1
		G->adj[w][v] = 1; // ""
	}
}

void GRAPHRemoveE(Graph G, Edge e){
	int v = e.v, w = e.w;
	if (G->adj[v][w] == 1){
		G->E--; // decrementa a qtd total de arestas
		G->adj[v][w] = 0; //remove correspondente da conexão
		G->adj[w][v] = 0; // ""
	}
}

int GRAPHEdges(Edge a[], Graph G){
	int v, w, E=0;
	for(v=0; v<G->V; v++){
		for (w=v+1; w<G->V; w++){
			if (G->adj[v][w] == 1){
				a[E++] = EDGE(v,w);
			}
		}
	}
	return E;
}
```

```ad-caution
title: Problema de usar matriz de adjacências

Por ocupar um espaço de $V^2$, sendo $V$ o número de vértices, esse método pode acabar desperdiçando uma grande quantidade de memória para representar as arestas, principalmente no caso de matrizes esparsas.
```

### Lista de adjacências
Teremos um vetor, em que cada indice do vetor representa um vertice, e cada posição é uma lista encadeada.

![[Pasted image 20250602163022.png]]

#### Prototipos
```c
typedef struct node *link;

struct node{
	int v;
	link next;
}

struct graph{
	int V, E;
	link *adj;
}
```

#### Alocação de um novo nó
```c
link NEW(int v, link next){
	link x = malloc(sizeof(*x));
	if(x == NULL){
		tela_azul();
		x->v = v;
		x->next = next;
		return x;
	}
}
```

#### Inicialização do grafo e inserção
Inicializamos o grafo com a alocação de um nó do tamanho G na memória, a quantidade de vértices sendo recebida como argumentos, a quantidade de vértices igual a 0 e alocando um vetor de V elementos do tipo link em adj.
Também inicializamos todos os links com NULL
```c
Graph GRAPHInit(int V){
	int v;
	Graph G = malloc(sizeof(*G));
	G->v = V;
	G->e = 0;
	G->adj = malloc(V*sizeof(link));
	for (v=0; v<V; v++){
		G->adj[v] = NULL;
	}
	return G;
}

void GRAPHInsert(Graph G, Edge e){
	int v = e.v, w = e.w;
	G->adj[v] = NEW(w, G->adj[v]);
	G->adj[w] = NEW(v, G->adj[w]);
	G->E++;
}
```

```ad-info
title: Adicionamos o nó no início da lista e não no fim
Isso porque é mais barato! 
No caso de um grafo completo, por exemplo, essa lista teria tamanho V e poderíamos percorrê-la inteira toda vez que quiséssemos buscar/inserir/remover uma aresta, o que tornaria a busca cara.
```

```c
int GRAPHEdges(Edge a[], Graph G){
	int v, E=0;
	link t;
	for(v=0; v<G->V; v++){
		for(t=G->adj[v]; t!=NULL; t= t->next){
			if(v<t->v){ //garante que uma mesma aresta não é adicionada duas vezes
				a[E++] = EDGE(v, t->v);
			}
		}
	}
	return E;
}
```

### Vetor x Matriz x Lista

|                         | Vetor de adj | Matriz de adj | Lista de adj. |
| ----------------------- | ------------ | ------------- | ------------- |
| Espaço                  | $E$          | $V^2$         | $V+E$         |
| Inicializar             | $1$          | $V^2$         | $V$           |
| Copiar                  | $E$          | $V^2$         | $E$           |
| Destruir                | $1$          | $V$           | $E$           |
| InserirE                | $1$          | $1$           | $1$           |
| EncontrarE/RemoverE     | $E$          | $V$           | $V$           |
| V é isolado?            | $E$          | $V$           | $1$           |
| Caminho de $u$ para $v$ | $ElgV$       | $V^2$         | $V+E$         |


## Vídeos do professor
<iframe width="560" height="315" src="https://www.youtube.com/embed/-CWbqWbNBTQ?si=hVguF1dOHbmpo18d" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

<iframe width="560" height="315" src="https://www.youtube.com/embed/pbOHGSbqgaM?si=TNNY0Xsx1tB2YLqg" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

## Bibliografia

> Prof. Bruno Ribas - **LIVE com os alunos - EDA2 a15**. Vídeo - 6 de nov. de 2020. 2h02min54s. Disponível em: [[https://youtu.be/-CWbqWbNBTQ](https://youtu.be/-CWbqWbNBTQ)]([https://youtu.be/-CWbqWbNBTQ](https://youtu.be/-CWbqWbNBTQ)). Acesso em: 02 de jun. de 2025. 
> 
> Prof. Bruno Ribas - **LIVE com os alunos - EDA2 a16**. Vídeo - 9 de nov. de 2020. 1h25min56s. Disponível em: [https://www.youtube.com/live/pbOHGSbqgaM?si=TNNY0Xsx1tB2YLqg](https://www.youtube.com/live/pbOHGSbqgaM?si=TNNY0Xsx1tB2YLqg). Acesso em: 02 de jun. de 2025. 