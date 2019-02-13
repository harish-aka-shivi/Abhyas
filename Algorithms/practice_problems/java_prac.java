import java.io.*;

class Solution {

  static{System.out.println("static block is invoked");}

  public void overMethod() {
    System.out.println("Solution over method");
  }

}

class Solution2 extends Solution {

  @Override
  public void overMethod() {
    System.out.println("Solution2 over method");
  }

}


class Solution3 {


  public static void main(String[] args) {
    System.out.println("public static int main()");
  }

}

class Solution4 {


  public static void main(String[] args) {
    Solution sol = new Solution2();
    sol.overMethod();
  }
}



class TestJoinMethod1 extends Thread{
  private String name = "";
  public TestJoinMethod1(String name) {
    this.name = name;
  }

 public void run(){
  for(int i=1;i<=5;i++){
   try{
    Thread.sleep(500);
   }catch(Exception e){
     System.out.println(e);
   }
  System.out.println(i + "  name => " + this.name);
  }
 }
public static void main(String args[]){
 TestJoinMethod1 t1=new TestJoinMethod1("t1");
 TestJoinMethod1 t2=new TestJoinMethod1("t2");
 TestJoinMethod1 t3=new TestJoinMethod1("t3");
 t1.start();
 try{
  t1.join();
 }catch(Exception e){
   System.out.println(e);
 }

 t2.start();
 t3.start();
 }
}
