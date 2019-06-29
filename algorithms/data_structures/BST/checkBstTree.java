
public class Solution {


//The Node class is defined as follows:
    private class Node {
        int data;
        Node left;
        Node right;
     }

  boolean checkBST(Node root) {
      if(root == null) {
          return true;
      }

       if(root.data > Integer.MAX_VALUE || root.data < Integer.MIN_VALUE) {
          return false;
      }

      if(!checkBST(root.left)) {
          return false;
      }

      if(root.left != null && root.left.data >= root.data) {
          return false;
      }

      if(!checkBST(root.right)) {
          return false;
      }

      if(root.right != null && root.right.data <= root.data) {
          return false;
      }
      return true;
    }


      // also this one
  boolean checkBST2(Node root) {
  	return check(root,Integer.MIN_VALUE,Integer.MAX_VALUE);
  }
  boolean check(Node n, int min, int max){
  	if(n==null)
  		return true;
  	if(n.data <= min || n.data >= max)
  		return false;
  	return check(n.left, min, n.data)
  		&& check(n.right, n.data, max);
  }
}
