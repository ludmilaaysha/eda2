# DFS
(Busca em Profundidade)

## Conceitos iniciais
- Quando falamos em **Busca em Profundidade**, falamos em ==pilha== 
	- Falamos em recursão
- A ideia é a seguinte:
	- Pense que está em um labirinto
	- Em cada ponto de encontro de caminhos, há algumas decisões a serem feitas sobre qual caminho seguir.
	- Uma DFS passa primeiro por todo o caminho até o final, depois volta ao último ponto de encontro, vai até o final, volta novamente, e assim por diante até ir pelo ultimo caminho possível

## Implementação
```c
void dfsR(Graph G, Edge e){ //recebe o grafo e a aresta de onde se inicia
	int t, w=e.w;
	pre[w]=cnt++; //o vertice visitado recebe o contador (que indica a ordem da visita). contador é incrementado no final
	for(t=0; t<G->V; t++){
		if (G->adj[w][t]!=0){ //se existe aresta entre vertices w e t
			if(pre[t] == -1){ // se t ainda não foi visitado
				dfsR(G, EDGE(w, t)); //chama a dfs para o proximo vertice
			}
		}
	}
}

int pre[v];

int main(){
	INICIAGRAPH();
	for (int v=0; v<G->V; v++){ //inicializa todos os vértices com -1 (não visitados)
		pre[v] = -1;
	}
	dfsR(G, EDGE(0,0));
}
```

```ad-note
title: Nota
Podemos fazer uma otimização para não visitarmos novamente uma aresta que já foi visitada.
```

Com listas de adjacências:
```c
void dfsR(Graph G, Edge e){ //recebe o grafo e a aresta de onde se inicia
	int t, w=e.w;
	link l;
	pre[w]=cnt++;
	for(l = G->adj[w]; l!=NULL; l=l->next){
		t = l->v;
		if(pre[t] == -1){ // se t ainda não foi visitado
			dfsR(G, EDGE(w, t)); //chama a dfs para o proximo vertice
		}
	}
}
```

## Vídeo do professor
<iframe width="560" height="315" src="https://www.youtube.com/embed/pbOHGSbqgaM?si=TNNY0Xsx1tB2YLqg" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

## Bibliografia
> Prof. Bruno Ribas - **LIVE com os alunos - EDA2 a16**. Vídeo - 9 de nov. de 2020. 1h25min56s. Disponível em: [https://www.youtube.com/live/pbOHGSbqgaM?si=TNNY0Xsx1tB2YLqg](https://www.youtube.com/live/pbOHGSbqgaM?si=TNNY0Xsx1tB2YLqg). Acesso em: 02 de jun. de 2025. 