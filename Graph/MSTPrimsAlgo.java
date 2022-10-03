
class MSTPrimsAlgo
{
    
    public static class Pair implements Comparable<Pair>{
        int v,wt;
        Pair(int v,int wt){
            this.v = v;
            this.wt = wt;
        }
        public int compareTo(Pair that){
            return this.wt-that.wt;
        }
        
    }
    
    //Function to find sum of weights of edges of the Minimum Spanning Tree.
    static int spanningTree(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj) 
    {
        boolean[] visited = new boolean[V];
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.offer(new Pair(0,0));
        int ans = 0;
        while(!pq.isEmpty()){
            Pair curr = pq.poll();
            if(visited[curr.v])continue;
            visited[curr.v] = true;
            ans += curr.wt;
            for(ArrayList<Integer> e : adj.get(curr.v)){
                if(!visited[e.get(0)]){
                    pq.offer(new Pair(e.get(0),e.get(1)));
                }
            }
        }
        return ans;
    }
}
