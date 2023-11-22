class Node {
    int data;
    Node left, right;

    public Node(int item) {
        data = item;
        left = right = null;
    }
}

class BinaryTree {

    Node root;

    boolean isSymmetric(Node root) {
        if (root == null)
            return true;
        return isMirror(root.left, root.right);
    }

    boolean isMirror(Node left, Node right) {
        if (left == null && right == null)
            return true;

        if (left != null && right != null && left.data == right.data)
            return isMirror(left.left, right.right) && isMirror(left.right, right.left);

        return false;
    }

    public static void main(String args[]) {
        BinaryTree tree = new BinaryTree();
        tree.root = new Node(5);
        tree.root.left = new Node(10);
        tree.root.right = new Node(10);
        tree.root.left.left = new Node(20);
        tree.root.left.right = new Node(20);
        tree.root.right.right = new Node(30);

        if (tree.isSymmetric(tree.root))
            System.out.println("True");
        else
            System.out.println("False");
    }
}
