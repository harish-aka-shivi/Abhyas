package com.staqu.infinity.standalone;
import java.util.*;


/*Markov takes out his Snakes and Ladders game and stares at the board, and wonders: If he had absolute control on the die (singular), and could get it to generate any number (in the range ) he desired, what would be the least number of rolls of the die in which he'd be able to reach the destination square (Square Number ) after having started at the base square (Square Number )?

Rules

    Markov has total control over the die and the face which shows up every time he tosses it. You need to help him figure out the minimum number of moves in which he can reach the target square (100) after starting at the base (Square 1).

    A die roll which would cause the player to land up at a square greater than 100, goes wasted, and the player remains at his original square. Such as a case when the player is at Square Number 99, rolls the die, and ends up with a 5.

    If a person reaches a square which is the base of a ladder, (s)he has to climb up that ladder, and he cannot come down on it. If a person reaches a square which has the mouth of the snake, (s)he has to go down the snake and come out through the tail - there is no way to climb down a ladder or to go up through a snake.

Constraints

The board is always of the size and Squares are always numbered to .



Square number 1 and 100 will not be the starting point of a ladder or a snake.
No square will have more than one of the starting or ending point of a snake or ladder (e.g. snake 56 to 44 and ladder 44 to 97 is not possible because 44 has both ending of a snake and a starting of a ladder)

Input Format

The first line contains the number of tests, T. T testcases follow.

For each testcase, the first line contain N(Number of ladders) and after that N line follow. Each of the N line contain 2 integer representing the starting point and the ending point of a ladder respectively.

The next line contain integer M(Number of snakes) and after that M line follow. Each of the M line contain 2 integer representing the starting point and the ending point of a snake respectively.

Output Format

For each of the T test cases, output one integer, each in a new line, which is the least number of moves (or rolls of the die) in which the player can reach the target square (Square Number 100) after starting at the base (Square Number 1). This corresponds to the ideal sequence of faces which show up when the die is rolled.
If there is no solution, print -1. */




public class SnakesAndLadders {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int testCases = in.nextInt();


        for(int e = 0; e < testCases; e++) {
            int laddersCount = in.nextInt();
            //System.out.println("ladders " + ladders);

            int[] laddersStart = new int[laddersCount];
            int[] laddersEnd = new int[laddersCount];

            for(int j=0;j<laddersCount;j++) {
                laddersStart[j] = in.nextInt();
                laddersEnd[j] = in.nextInt();
            }
            int snakes = in.nextInt();
            //System.out.println("snakes" + snakes);
            int[] snakesStart = new int[snakes];
            int[] snakesEnd = new int[snakes];
            for(int k=0; k<snakes;k++) {
                snakesStart[k] = in.nextInt();
                snakesEnd[k] = in.nextInt();

            }
            int lengthStart  = laddersStart.length + snakesStart.length;
            int lengthEnd = laddersEnd.length + snakesEnd.length;
            int[] start = new int[lengthStart];
            int[] end = new int[lengthEnd];

            for(int l = 0; l < laddersCount; l++) {
                start[l] = laddersStart[l];
                end[l] = laddersEnd[l];
            }
            int o =0;
            for(int m = laddersCount; m<lengthEnd; m++) {
                start[m] = snakesStart[o];
                end[m] = snakesEnd[o];
                o++ ;
            }

            LinkedHashMap<Integer,LinkedList> hm = new LinkedHashMap<Integer,LinkedList>();
            //this initializes hash map
            boolean [] visited = new boolean[101];
            for( int i = 1;i<=100;i++) {
                hm.put(i,new LinkedList<Integer>());
            }

            //initializes simple board game without snakes and letter
            initializeTheBoard(hm);

            //initializes board with snakes and letter.
            initializeWithSnakesAndLadder(hm,start,end);


            int[] moves = new int[101];
            for(int i = 0; i < 101; i++ ) {
                moves[i] = 0;
            }
            LinkedList<Integer> queue = new LinkedList<Integer>();
            visited[1] = true;
            queue.add(1);
            int parent;
            while(queue.size() !=0) {
                int trav = queue.poll();
                //System.out.print(trav + " ");

                parent = trav;
                LinkedList ll = hm.get(trav);

                Iterator<Integer> i = ll.listIterator();

                while(i.hasNext())  {
                    int n = i.next();
                    if(!visited[n]) {
                        visited[n] = true;
                        queue.add(n);
                        moves[n] = moves[parent] + 1;
                    }
                }
            }

            if(visited[100]){
                System.out.println(moves[100]);
            } else {
                System.out.println("-1");
            }

        }

    }



    private static void initializeTheBoard(LinkedHashMap<Integer,LinkedList> hm) {
        for(int i =1; i <= 100; i++ ){
            LinkedList lil = hm.get(i);

            for(int j=1; j<=6; j++) {
                int k = i+j;
                if (k <=100) {
                    lil.add(k);
                }
            }
        }
    }


    private static void initializeWithSnakesAndLadder(LinkedHashMap<Integer,LinkedList> hm,
                                                      int[] start,int[] end) {
        for(int k =0; k<start.length; k++) {
            hm.remove(start[k]);

            for (int i=1;i<=6;i++) {
                int j = start[k] - i;

                LinkedList li = hm.get(j);
                //System.out.println("list = " + li);
                if(li != null){
                    int ind = li.indexOf(start[k]);
                    li.remove(ind);

                    li.add(end[k]);
                    //System.out.println("list after = " + li);
                }
            }
        }
    }



}
