# Grafo dirigido
(ou *digraph*)

## Conceitos iniciais
### Grafo dirigido
> É um conjunto de vértices e um conjunto de arestas dirigidas que conectam um par de vertices (SEM ARESTAS DUPLICADAS). Dizemos que uma aresta vai DE um primeiro vértice PARA o seu segundo vértice (RIBAS, 2020).

```c
Edge {
	int v, w; // v é primeiro, w é segundo
}
```

### Caminho dirigido
> Em um dígrafo, é uma lista de vértices no qual existe uma aresta dirigida conectando cada vértice da lista a seu sucessor. Dizemos que de um vértice `t` é **alcançável** de um vértice `s` se existe um caminho dirigido de `s` a `t` (RIBAS, 2020).

### Métricas
- A quantidade de arestas em um grafo não dirigido pode ser até $V^2$
- Se temos um grafo dirigido, esse número aumenta: $2^{v^2}$

## DAG (Grafo Dirigido Acíclico)
> É um grafo dirigido que não possui ciclos (RIBAS, 2020).

Se saio de um vértice v qualquer, nunca conseguirei chegar nele novamente. Se saio dele, nunca conseguirei retornar a um vértice acima dele na ordenação topológica.
- Exemplo de DAG são **árvores**
	- Sistemas de arquivos são árvores/DAGs

## Grafo Dirigido fortemente conexo
> Se todos os vértices são alcançáveis a partir de todos os vértices

## Inverter arestas de um grafo dirigido
Podemos fazer isso utilizando as ferramentas que já temos no nosso arsenal
- No caso de um grafo representado por listas encadeadas:
```c
Graph GRAPHreverse(Graph G){
	int v; link t;
	Graph R = GRAPHinit(G->v);
	for (v=0; v<G->V; v++){
		for (t= G->adj[v]; t!=NULL; t=t->next){
			GRAPHinsert(R, EDGE(t->v, v));
		}
	}
	return R;
}
```
- No caso de matriz de adjacências, podemos só interpretar a matriz de outra forma: o que era interpretado como coluna passa a ser linha e vice-versa
	- Outras operações, como calcular a transposta, podem ser caras.

## Fecho transitivo
> É um grafo dirigido com o mesmo conjunto de vértices mas com uma aresta de `s` e `t` no fecho transitivo se, e somente se, existe um caminho dirigido de `s` a `t` no grafo dirigido (RIBAS, 2020).

Ou seja, é um outro grafo que representa por quais vértices pode chegar a partir de cada vértice, mesmo que não tenha ligação direta, se ele pode alcançar outros vértices, o fecho **transitivo representa** isso.


## Floyd Warshall
É um algoritmo que cria esse grafo do fecho transitivo, o qual estabelece todas os alcances de todos os vértices

- O código abaixo apresenta esse algoritmo. É um algoritmo muito custoso!! $O(V^3)$
	- Contudo, para fazer buscas posteriores, há uma economia de memória muito grande

```c
void GRAPHtc(Graph G){
	int i, s, t;
	G->tc = MATRIXint(G->V, G->V, 0); // tc é um extra que está atuando como suporte de ponteiro de ponteiro. ajuda no fecho transitivo. cria tc inicializando todos com 0
	for(s=0; s<G->V; s++){
		for (t=0; t<G->V; t++){
			G->tc[s][t] = G->adj[s][t]; // copia a matriz adj para tc
		}
	}
	
	for(s=0; s<G->V; s++){
		G->tc[s][s]=1; // indica que todo vértice alcança a si mesmo
	}
	
	for(i=0; i<G->V; i++){ i=1
		for(s=0; s<G->V; s++){ s=0
			if(G->tc[s][i] == 1){ tc[0][1]
				for(t=0; t<G->V; t++){ t=0
					if(G->tc[i][t] == 1){ tc[1][0]
						G->tc[s][t] = 1; tc[0][0]
					}
				}
			}
		}
	}
}
```



Descobrir a alcançabilidade de um grafo G
```c
int GRAPHreach(Graph G, int s, int t){
	return G->tc[s][t]
}
```

## Video do professor
<iframe width="560" height="315" src="https://www.youtube.com/embed/w6w0LW_7Ins?si=saG87EnY88KyhyVm" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
## Bibliografia
> Prof. Bruno Ribas - **LIVE com os alunos - EDA2 a19**. Vídeo - 23 de nov. de 2020. 1h36min40s. Disponível em: [https://www.youtube.com/live/w6w0LW_7Ins?si=saG87EnY88KyhyVm](https://www.youtube.com/live/w6w0LW_7Ins?si=saG87EnY88KyhyVm). Acesso em: 03 de jun. de 2025. 