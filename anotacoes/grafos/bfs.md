# BFS
(Busca em Largura)

## Conceitos iniciais
- Em uma [[dfs | DFS]], o grafo é percorrido por um caminho inteiro até o fim antes de entrar em outro.
- Isso por conta do algoritmo que é recursivo, e usa pilha.
- Uma outra alternativa que temos é ir analisando os vizinhos antes de chegar ao fim do caminho. Fazemos isso com busca em largura, ou **BFS**
	- Assim, a BFS não é recursiva, pois usa um conceito de FILA

## Implementação
### Como fazer?
1. Implementamos uma fila
2. Já enfileiramos a aresta inicial e já marcamos o count++ nessa posição no pre
3. Começamos a percorrer a fila enquanto ela não for vazia: pegamos topo da fila, marcamos essa aresta no pre e enfileiramos as arestas as quais o topo se liga

### Código

```c
void bfs(Graph G, Edge e){
	int v, w;
	QUEUEput(e); 
	pre[e.w] = cnt++;
	while(!QUEUEEmpty()){
		e = QUEUEGet();
		w = e.w;
		for(l=G->adj[w]; l!=NULL; l = l->next){
			if(pre[t] == -1){
				QUEUEPut(EDGE(w, t));
				pre[t] = cnt++;
			}
		}
	}
}
```

## Video do professor
<iframe width="560" height="315" src="https://www.youtube.com/embed/DlE2C0TTxqk?si=FPV7NnEsbyJf53oy" title="YouTube video player" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture; web-share" referrerpolicy="strict-origin-when-cross-origin" allowfullscreen></iframe>
## Bibliografia
> Prof. Bruno Ribas - **LIVE com os alunos - EDA2 a18**. Vídeo - 20 de nov. de 2020. 1h8min8s. Disponível em: [https://www.youtube.com/live/DlE2C0TTxqk?si=FPV7NnEsbyJf53oy](https://www.youtube.com/live/DlE2C0TTxqk?si=FPV7NnEsbyJf53oy). Acesso em: 03 de jun. de 2025. 