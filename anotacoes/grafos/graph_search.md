# graph_search
(Busca em grafos)

## Conceitos iniciais
- Vimos que, com uma [[dfs | DFS]], conseguimos saber em quantos vértices conseguimos chegar a partir de um, bem como a ordem de visita.
- E se quisermos saber quantas [[intro_a_grafos#Grafo conexo | componentes conexas]] temos em um grafo?
	- A ideia é fazer um `for` para todos os vértices, rodando uma [[dfs#Implementação| DFS]] para cada um e verificando se o vértice já foi visitado

```c
static int cnt, pre[maxV];
void GRAPHSearch(Graph G){
	int v, conexos = 0;
	cnt = 0;
	for(v=0; v<G->V; v++){
		pre[v] = -1;
	}
	for(v=0; v<G->V; v++){
		if(pre[v] == -1){ // se não tiver sido visitado, rodamos a dfs e incrementamos o conexos
			dfsR(G, EDGE(v,v));
			conexos++;
		}
	} 
}
```

No caso de um problema de grafos que utiliza listas de adjacências, em que temos a dfs
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


## Video do professor
<iframe width="560" height="315" src="https://www.youtube.com/embed/pOkjep6hpuA?si=X4Wv50yd5kgz3O8a" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>

## Bibliografia
> Prof. Bruno Ribas - **LIVE com os alunos - EDA2 a17**. Vídeo - 13 de nov. de 2020. 1h11min17s. Disponível em: [https://www.youtube.com/live/pOkjep6hpuA?si=oy2o46cwsWB-SGa7](https://www.youtube.com/live/pOkjep6hpuA?si=oy2o46cwsWB-SGa7). Acesso em: 02 de jun. de 2025. 