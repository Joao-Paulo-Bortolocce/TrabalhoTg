char verificaSimplesAdjacenciaMI(int arestas[TFL*TFL][2], int tl){
    int i,j,k;
    for(i=0;i<tl && arestas[i][0] != arestas[i][1];i++);
    if(i == tl){
    	for(i=0;i<tl-1; i++){
    		for(j = i+1; j < tl; j++){
    			if(arestas[i][0] == arestas[j][1] || arestas[i][0] == arestas[j][1])
    		}
    	}
    }
}
