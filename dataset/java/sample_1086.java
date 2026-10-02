public class sample_1086 {
    static class Node {
        int value;
        Node[] neighbors;

        Node(int value) {
            this.value = value;
            this.neighbors = new Node[0];
        }
    }

    static void add_edge(Node a, Node b) {
        Node[] newNeighborsA = new Node[a.neighbors.length + 1];
        System.arraycopy(a.neighbors, 0, newNeighborsA, 0, a.neighbors.length);
        newNeighborsA[a.neighbors.length] = b;
        a.neighbors = newNeighborsA;

        Node[] newNeighborsB = new Node[b.neighbors.length + 1];
        System.arraycopy(b.neighbors, 0, newNeighborsB, 0, b.neighbors.length);
        newNeighborsB[b.neighbors.length] = a;
        b.neighbors = newNeighborsB;
    }

    static Node[] find_path(Node start, Node end, Node[] path) {
        Node[] newPath = new Node[path.length + 1];
        System.arraycopy(path, 0, newPath, 0, path.length);
        newPath[path.length] = start;
        if (start == end) {
            return newPath;
        }
        for (Node node : start.neighbors) {
            boolean inPath = false;
            for (Node p : newPath) {
                if (p == node) {
                    inPath = true;
                    break;
                }
            }
            if (!inPath) {
                Node[] newpath = find_path(node, end, newPath);
                if (newpath != null) {
                    return newpath;
                }
            }
        }
        return null;
    }

    public static void main(String[] args) {
        Node a = new Node(1);
        Node b = new Node(2);
        Node c = new Node(3);
        Node d = new Node(4);
        Node e = new Node(5);
        add_edge(a, b);
        add_edge(b, c);
        add_edge(c, d);
        add_edge(d, e);
        add_edge(e, a);
        while (true) {
            Node[] result = find_path(a, e, new Node[0]);
            if (result != null) {
                for (Node node : result) {
                    System.out.print(node.value + " ");
                }
                System.out.println();
            }
        }
    }
}