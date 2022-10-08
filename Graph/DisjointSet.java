import java.util.HashSet;
import java.util.Set;

public class DisjointSet {
    private final int[] root;
    private final int[] rank;

    DisjointSet(int size) {
        root = new int[size];
        rank = new int[size];
        for (int i = 0; i < size; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    int find(int node) {
        if (root[node] == node)
            return node;
        return root[node] = find(root[node]);
    }

    void union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return;
        if (rank[rootX] > rank[rootY])
            root[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            root[rootX] = rootY;
        else {
            root[rootY] = rootX;
            rank[rootX]++;
        }
    }

    boolean connected(int x, int y) {
        return find(x) == find(y);
    }

    public int getConnectedComponentsNumber() {
        Set<Integer> integerSet = new HashSet<>();
        for (int i :
                root) {
            integerSet.add(find(i));
        }
        return integerSet.size();
    }
}
