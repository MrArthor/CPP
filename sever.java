ANS6)
(1)
Contest.java:
import java.io.*;
import java.util.*;

public class Contest
{
   static Question questionclass[] = new Question[4]; 
   static Contestant contestantclass[] = new Contestant[4];
   static Lifelines lifelineclass[] = new Lifelines [4];
   public static void main (String[] args)
   {
      Scanner scanner = new Scanner (System.in);
      int value = 500, values [] = new int [] {500, 1000, 2000, 5000, 10000, 20000, 50000, 75000, 150000, 250000, 500000, 1000000}, money[] = new int [4], winnervalue=0, count = 0;
      String question="", a = "", b = "", c = "", d = "", answer="", hint = "", names[] = new String [4], response = "";
      boolean rightwrong = false, quit = false;
      for (int i = 0; i<4; i++) 
      {
         questionclass[i]= new Question (); 
         questionclass[i].question(); 
         contestantclass[i] = new Contestant(); 
         contestantclass[i].contestant(); 
         names = contestantclass[i].getNames(); 
         lifelineclass[i] = new Lifelines (); 
         lifelineclass[i].lifelines (a, b, c, d, answer, question, hint, values[i]); 
      }
      System.out.println("\t\t-----------------------------");
      System.out.println("\t\tWho Wants to be a Millionaire");
      System.out.println("\t\t-----------------------------");
      for (int i = 0; i<4; i++) 
      {
         count = 0;
         quit = false;
         value = 500; 
         questionclass[i].resetBuffer();
         lifelineclass[i].resetLifelines(); 
         do 
         {
            lifelineclass[i].newValue(value); 
            if (value == 500)
            {
               System.out.println(names[i]+", It's Your Turn to play...... Who wants to be a Millionaire! Piracy Edition\n"); 
            }
            for (int j = 1; j<=7; j++) 
            {
               if (j == 1)
               {
                  question = questionclass[i].getQuestion
                  System.out.println("For $"+value+"....... "+question);
               }
               if (j == 2)
               {
                  a = questionclass[i].getA(); 
                  System.out.println(a);
               }
               if (j == 3)
               {
                  b = questionclass[i].getB(); 
                  System.out.println(b);
               }
               if (j == 4)
               {
                  c = questionclass[i].getC(); 
                  System.out.println(c);
               }
               if (j == 5)
               {
                  d = questionclass[i].getD(); 
                  System.out.println(d);
               }
               if (j == 6)
               {
                  answer = questionclass[i].getAnswer(); 
               }
               if (j == 7)
               {
                  hint = questionclass[i].getHint(); 
               }
            }
            if (lifelineclass[i].hasLifeline()) 
            {
               System.out.println("\ne) Use a lifeline");
               if (value == 500) 
               {
                  System.out.println();
               }
            }
            lifelineclass[i].resetAnswers(a, b, c, d); 
            if (value != 500&&lifelineclass[i].hasLifeline() == false) 
            {
               System.out.println("\nf) Walk out\n");
            }
            else  if (value != 500) 
            {
               System.out.println("f) Walk out\n");
            }
            do 
            {
               System.out.print("Enter your answer: ");
               response = scanner.nextLine(); 
               response = response.toLowerCase(); 
               if (response.charAt(0)<97|| response.charAt(0)>102) 
               {
                  System.out.println("Invalid Entry!");
               }
               if (lifelineclass[i].hasLifeline() == false&&response.compareTo("e")==0) 
               {
                  System.out.println("Invalid Entry! You are out of Lifeline!");
               }
               if (response.compareTo("f")==0&&value==500) 
               {
                  System.out.println("You cannot quit on the first turn!");
               }
            } while ((response.charAt(0)<97|| response.charAt(0)>102)||(lifelineclass[i].hasLifeline() == false&&response.compareTo("e")==0)|| (response.compareTo("f")==0&&value==500));
            if (response.compareTo("e")==0&&lifelineclass[i].hasLifeline()) 
            {
               do 
               {
                  response = lifelineclass[i].useLifeline(a, b, c, d, answer, question, hint);
               } while (response.compareTo("e")==0);
            }
            if (response.compareTo("f")==0&&value != 500) 
            {
               System.out.println("Thanks for playing!");
               quit = true; 
            }
            if (lifelineclass[i].hasLifeline() == false) 
            {
               if (response.compareTo("e") == 0) 
               {
                  do{ 
                     System.out.print("You are out of lifelines!\nEnter your response again: ");
                     response = scanner.nextLine();
                  } while (response.compareTo("a")!=0&&response.compareTo("b")!=0&&response.compareTo("c")!=0&&response.compareTo("d")!=0&&response.compareTo("f")!=0);
               }
            }
            if (response.compareTo(answer) == 0) 
            {
               rightwrong = true;
            }
            else 
            {
               rightwrong = false;
            }
            if (rightwrong == true&&value!=1000000) 
            {
               System.out.println ("\nWell done! "+answer+" is correct!\n");
               value = values[count+1];
            }
            else if (rightwrong == true&&value==1000000)  
            {
               System.out.println("Congratulations!!!! You have now won One Million Dollars!\n");
               contestantclass[i].setValue(value, names[i]); 
               rightwrong = false;
            }
            else if (rightwrong == false&&response.compareTo("f")!=0) 
            {
               value = contestantclass[i].getLastValue(value, rightwrong); 
               contestantclass[i].setValue(value, names[i]); 
               System.out.println("\nSorry, You are Incorrect! The correct answer was: "+answer);
               System.out.println("You are going home with.......... $" + value+"\n");
            }
            else if (rightwrong == false&&response.compareTo("f")==0) 
            {
               value = contestantclass[i].getExitValue(value); 
               contestantclass[i].setValue(value, names[i]); 
               System.out.println("\nYou have decided to leave the game! The correct answer was: "+answer);
               System.out.println("You are going home with.......... $" + value+"\n");
            }
            count++; 
            lifelineclass[i].resetSameturn();
         }  while (rightwrong != false && value<=1000000 && quit!=true); 
      }
      money = contestantclass[1].getArray(); 
      for (int i = 0; i<4; i++) 
      {
         if (i == 0) 
         {
            winnervalue = money[i];
         }
         else
         {
            if (money[i]>winnervalue) 
            {
               winnervalue = money[i]; 
            }
         }
      }
      System.out.println("Results"); 
      for (int i = 0; i<4; i++) 
      {
         System.out.println(names[i]+"\t$"+money[i]);
      }
      if (winnervalue!=0) 
      {
         System.out.print ("The winners are: ");
      }
      else if (winnervalue == 0) 
      {
         System.out.print ("Nobody Won!");
      }
      for (int i = 0; i<4; i++) 
      {
         if (money[i] == winnervalue&&money[i]!=0&&winnervalue!=0) 
         {
            System.out.print(names[i]+", ");
         }
      }
   }
}

(2) Contestant.java:
import java.io.*;
   import java.util.*;
   public class Contestant
   {
      static FileReader file;
      static BufferedReader buffer;
      static String names[] = new String [4];
      static int money[] = new int [4], contestantnum, moneynum;
      static int values [] = new int [] {500, 1000, 2000, 5000, 10000, 20000, 50000, 75000, 150000, 250000, 500000, 1000000};
      public void contestant()
      {
         try
         {
            file = new FileReader("contestants.txt"); 
            buffer = new BufferedReader(file);
         }
            catch (IOException e)
            {

            }
      }
      public String[] getNames()
      {
         try
         {
            for (int i = 0; i<4; i++) 
            {
               names[i]=buffer.readLine();
            }
         }
            catch (IOException e)
            {

            }
         return names; 
      }
      public int getMoney(int value)
      {
         int newvalue = 0;
         for (int i = 0; i<12; i++)
         {
            if (value == values[i])
            {
               newvalue = values[i+1]; 
               break; 
            }
            else
            {
               newvalue = value; 
            }
         }
         return newvalue; 
      }
      public int getLastValue(int value, boolean rightwrong)
      {
         int lastvalue = 0; 
         for (int i = 0; i<12; i++) 
         {
            if (value == 500) 
            {
               lastvalue = 0;
            }
            else if (value == 1000&&rightwrong == false) 
            {
               lastvalue = 0; 
            }
            else if (value == 1000||value>=1000&&value<50000)
            {
               lastvalue = 1000; 
            }
            else if (value ==50000||value>=50000&&value<1000000) 
            {
               lastvalue = 50000; 
            }
            else if (value ==1000000&&rightwrong == false) 
            {
               lastvalue = 50000; 
            }
         }
         return lastvalue; 
      }
      public int getExitValue(int value)
      {
         int lastvalue = 0; 
         for (int i = 0; i<12; i++) 
         {
            if (value == values[i]&&value!=1000) 
            {
               lastvalue = values[i-1];
            }
            else if (value == values[i]&&value==1000) 
            {
               lastvalue = 500;
            }
         }
         return lastvalue; 
      }
      public void setValue (int value, String name)
      {
         int index = 0; 
         for (int i = 0; i<4; i++) 
         {
            if (names[i].compareTo(name)==0) 
            {
               index = i; 
            }
         }
         money [index] = value; 
      }
      public int[] getArray()
      {
         return money;
      }
   }

(3) Lifeline.java:
  import java.io.*;
   import java.util.*;
   public class Lifelines
   {
      static String lifelines[] = {"25-75", "50-50", "HINT"};
      static int numLifelines=3, value = 0;
      static Scanner scanner = new Scanner(System.in);
      static String[] answers = new String[4];
      static String a, b, c, d, question, hint;
      static boolean haslife = true, sameturn = false;
      public void lifelines(String ma, String mb, String mc, String md, String manswer, String mquestion, String mhint, int mvalue)
      {
         a = ma;
         b= mb;
         c = mc;
         d = md;
         question = mquestion;
         hint = mhint;
         answers = new String[] {a, b, c, d};
         value = mvalue;
      }
      public boolean hasLifeline()
      {
         if (numLifelines>0) 
         {
            return true; 
         }
         else
         {
            return false; 
         }
      }
      public String useLifeline(String a, String b, String c, String d, String answer, String question, String hint)
      {
      	
         String fa = Character.toString(a.charAt(0)), fb=Character.toString(b.charAt(0)), fc=Character.toString(c.charAt(0)), fd=Character.toString(d.charAt(0)), useranswer = "";
         String choice;
         boolean choicevar = false, exit = false;
         Random random = new Random();
         int randomnum;
         if (hasLifeline()) 
         {
            System.out.println("\nYou have exactly "+numLifelines+" Lifelines remaining");
            for (int i = 0; i<3; i++)
            {
               if (lifelines[i]!="")
               {
                  System.out.println(lifelines[i]+" ");
               }
            }
            do 
            {
               exit = false; 
               System.out.print("Enter a Lifeline to use: ");
               choice = scanner.nextLine(); 
               if (choice.compareTo("25-75")==0&&lifelines[0].compareTo("")==0) // Sees if they have the 25-75 lifeline
               {
                  System.out.println("Error! Invalid Entry");
                  exit = true;
               }
               else if (choice.compareTo("50-50")==0&&lifelines[1].compareTo("")==0) // Sees if they have the 50-50 lifeline
               {
                  System.out.println("Error! Invalid Entry");
                  exit = true;
               }
               else if (choice.compareTo("HINT")==0&&lifelines[2].compareTo("")==0) 
               {
                  System.out.println("Error! Invalid Entry");
                  exit = true;
               }
               if (exit != true && choice != "50-50") 
               {
                  if (choice.compareTo(lifelines[0])!=0&&choice.compareTo(lifelines[1])!=0&&choice.compareTo(lifelines[2])!=0) // If the choice does not equal any lifeline, it outputs an error message
                  {
                     System.out.println("Error! Invalid Entry");
                     exit = true;
                  }
               }
            } while (exit == true);
            if (choice.compareTo("25-75")==0&&sameturn == false) 
            {
               if (lifelines[0].compareTo("")!=0) 
               {
                  if (answer.compareTo(fa)==0) 
                  {
                     answers = new String[] {b, c, d}; 
                  }
                  else if (answer.compareTo(fb)==0) 
                  {
                     answers = new String[] {a, c, d}; 
                  }
                  else if (answer.compareTo(fc)==0) 
                  {
                     answers = new String[] {a, b, d}; 
                  }
                  else if (answer.compareTo(fd)==0) 
                  {
                     answers = new String[] {a, b, c}; 
                  }
                  randomnum = random.nextInt(3); 
                  answers[randomnum] = answer; 
                  Arrays.sort(answers); 
                  System.out.println("\n"+question); 
                  for (int i = 0; i<3; i++) 
                  {
                     if (a.charAt(0) == answers[i].charAt(0)) 
                     {
                        answers[i] = a; 
                        System.out.println(a+" ");
                     }
                     if (b.charAt(0) == answers[i].charAt(0)) 
                     {
                        answers[i] = b; 
                        System.out.println(b+" "); 
                     }
                     if (c.charAt(0) == answers[i].charAt(0)) 
                     {
                        answers[i] = c; 
                        System.out.println(c+" "); 
                     }
                     if (d.charAt(0) == answers[i].charAt(0)) 
                     {
                        answers[i] = d; 
                        System.out.println(d+" ");
                     }
                  }
                  if (hasLifeline()) 
                  {
                     System.out.println("\ne) Use a lifeline");
                  }
                  if (value != 500) 
                  {
                     System.out.println("f) Give up\n");
                  }
                  numLifelines--; 
                  do 
                  {
                     System.out.print("Enter your answer: ");
                     useranswer = scanner.nextLine(); 
                     useranswer = useranswer.toLowerCase(); 
                     if (useranswer.charAt(0)<97|| useranswer.charAt(0)>102) 
                     {
                        System.out.println("Invalid Entry!");
                     }
                     if (useranswer.compareTo("e")== 0&& haslife == false) 
                     {
                        System.out.println("Error! You are out of Lifelines!");
                        do 
                        {
                           System.out.print("Enter your answer: ");
                           useranswer = scanner.nextLine(); 
                           useranswer = useranswer.toLowerCase(); 
                           if (useranswer.charAt(0)<97|| useranswer.charAt(0)>102) 
                           {
                              System.out.println("Invalid Entry!");
                           }
                           if (useranswer.compareTo("e")== 0&& haslife == false) 
                           {
                              System.out.println("Error! You are out of Lifelines!");
                           }
                        } while (useranswer.compareTo("e")== 0 ||(useranswer.charAt(0)<97|| useranswer.charAt(0)>102)); 
                     }
                     if (useranswer.compareTo("f")==0&&value==500) 
                     {
                        System.out.println("You cannot quit on the first turn!");
                     }
                  } while ((useranswer.charAt(0)<97|| useranswer.charAt(0)>102)||(useranswer.compareTo("f")==0&&value==500)); 
                  lifelines[0]=""; 
               }
               else if (choice.compareTo("25-75")==0&&sameturn == true) 
               {
                  System.out.println("If you use this lifeline you will get the same results you already have.\n");
                  System.out.println(question); 
                  for (int i = 0; i<answers.length; i++)
                  {
                     System.out.println(answers[i]); 
                  }
                  if (hasLifeline())
                  {
                     System.out.println("\ne) Use a lifeline\n"); 
                  }
                  System.out.println("Enter your answer: ");
                  useranswer = scanner.nextLine(); 
               }
            }
            else if (choice.compareTo("50-50")==0&&lifelines[1]!="") 
            {
               if (answer.compareTo(fa)==0) 
               {
                  answers = new String[] {b, c, d}; 
               }
               else if (answer.compareTo(fb)==0) 
               {
                  answers = new String[] {a, c, d}; 
               }
               else if (answer.compareTo(fc)==0) 
               {
                  answers = new String[] {a, b, d}; 
               }
               else if (answer.compareTo(fd)==0) 
               {
                  answers = new String[] {a, b, c}; 
               }
               randomnum = random.nextInt(3); 
               answers[randomnum] = "";
               if (randomnum == 0) 
               {
                  answers = new String[] {answers[1], answers[2]}; 
               }
               else if (randomnum == 1) 
               {
                  answers = new String[] {answers[0], answers[2]}; 
               }
               else if (randomnum == 2) 
               {
                  answers = new String[] {answers[0], answers[1]}; 
               }
               randomnum = random.nextInt(2); 
               answers[randomnum] = answer; 
               Arrays.sort(answers); 
               System.out.println("\n"+question); 
               for (int i = 0; i<2; i++) 
               {
                  if (a.charAt(0) == answers[i].charAt(0)) 
                  {
                     answers[i] = a; 
                     System.out.println(a+" "); 
                  }
                  if (b.charAt(0) == answers[i].charAt(0)) 
                  {
                     answers[i] = b; 
                     System.out.println(b+" "); 
                  }
                  if (c.charAt(0) == answers[i].charAt(0)) 
                  {
                     answers[i] = c; 
                     System.out.println(c+" "); 
                  }
                  if (d.charAt(0) == answers[i].charAt(0)) 
                  {
                     answers[i] = d; 
                     System.out.println(d+" "); 
                  }
               }
               numLifelines--; 
               if (hasLifeline()) 
               {
                  System.out.println("\ne) Use a lifeline"); 
               }
               if (value != 500) 
               {
                  System.out.println("f) Give up\n"); 
               }
               else
               {
                  System.out.println(); 
               }
               do{ 
                  System.out.print("Enter your answer: ");
                  useranswer = scanner.nextLine(); 
                  useranswer = useranswer.toLowerCase(); 
                  if (useranswer.charAt(0)<97|| useranswer.charAt(0)>102) 
                  {
                     System.out.println("Invalid Entry!");
                  }
                  if (useranswer.compareTo("f")==0&&value==500) 
                  {
                     System.out.println("You cannot quit on the first turn!");
                  }
               } while ((useranswer.charAt(0)<97|| useranswer.charAt(0)>102)||(useranswer.compareTo("f")==0&&value==500)); 
               lifelines[1]=""; 
               sameturn = true;
            }
            else if (choice.compareTo("HINT")==0&&lifelines[2]!="") 
            {
               System.out.println("\n"+question);
               for (int i = 0; i<answers.length; i++)
               {
                  System.out.println(answers[i]); 
               }
               numLifelines--; 
               if (hasLifeline())
               {
                  System.out.println("\ne) Use a lifeline"); 
               }
               if (value != 500) 
               {
                  System.out.println("f) Give up\n");
               }
               System.out.println("\n"+hint+"\n"); 
               do 
               {
                  System.out.print("Enter your answer: ");
                  useranswer = scanner.nextLine(); 
                  useranswer = useranswer.toLowerCase(); 
                  if (useranswer.charAt(0)<97|| useranswer.charAt(0)>102) 
                  {
                     System.out.println("Invalid Entry!");
                  }
                  if (useranswer.compareTo("e")== 0&& haslife == false) 
                  {
                     System.out.println("Error! You are out of Lifelines!");
                     do 
                     {
                        System.out.print("Enter your answer: ");
                        useranswer = scanner.nextLine(); 
                        useranswer = useranswer.toLowerCase(); 
                        if (useranswer.charAt(0)<97|| useranswer.charAt(0)>102) // Checks to see if the answer is between a and f
                        {
                           System.out.println("Invalid Entry!");
                        }
                        if (useranswer.compareTo("e")== 0&& numLifelines<=0) 
                        {
                           System.out.println("Error! You are out of Lifelines!");
                        }
                     } while (useranswer.compareTo("e")== 0 ||(useranswer.charAt(0)<97|| useranswer.charAt(0)>102)); 
                  }
                  if (useranswer.compareTo("f")==0&&value==500) 
                  {
                     System.out.println("You cannot quit on the first turn!"); 
                  }
               } while ((useranswer.charAt(0)<97|| useranswer.charAt(0)>102)||(useranswer.compareTo("f")==0&&value==500)); 
               lifelines[2] = ""; 
               answers = new String[4]; 
            }
         }
         else 
         {
            System.out.println("Error! You are out of Lifelines!"); 
            do 
            {
               System.out.print("Enter your answer: ");
               useranswer = scanner.nextLine(); 
               useranswer = useranswer.toLowerCase(); 
               if (useranswer.charAt(0)<97|| useranswer.charAt(0)>102) 
               {
                  System.out.println("Invalid Entry!");
               }
               if (useranswer.compareTo("e")== 0&& numLifelines<=0) 
               {
                  System.out.println("Error! You are out of Lifelines!");
               }
            } while (useranswer.compareTo("e")== 0 ||(useranswer.charAt(0)<97|| useranswer.charAt(0)>102)); 
         }
         return useranswer; 
      }
      public void resetLifelines () 
      {
         numLifelines = 3; 
         lifelines = new String[] {"25-75", "50-50", "HINT"}; 
      }
      public void resetAnswers (String ma, String mb, String mc, String md) 
      {
         answers = new String[] {ma, mb, mc, md}; 
      }
      public void newValue (int mvalue) 
      {
         value = mvalue; 
      }
      public void resetSameturn () 
      {
         sameturn = false; 
      }
   }

(4) Questions.java:
   import java.io.*;
   import java.util.*;
   public class Question
   {
      static FileReader file;
      static BufferedReader buffer;
      static String question , a, b, c, d, answer, hint;
      static int value;
      public void question() 
      {
         try
         {
            file = new FileReader("questions.txt"); 
            buffer = new BufferedReader(file); 
         }
            catch (IOException e)
            {

            }
      }
      public String getQuestion()
      {
         try
         {
            question = buffer.readLine(); 
         }
            catch (IOException e)
            {

            }
         return question;
      }
      public String getA() 
      {
         try
         {
            a  = buffer.readLine(); 
         }
            catch (IOException e)
            {

            }
         return a;
      }
      public String getB()
      {
         try
         {
            b  = buffer.readLine();
         }
            catch (IOException e)
            {

            }
         return b;
      }
      public String getC() 
      {
         try
         {
            c  = buffer.readLine(); 
         }
            catch (IOException e)
            {

            }
         return c;
      }
      public String getD() 
      {
         try
         {
            d  = buffer.readLine(); 
         }
            catch (IOException e)
            {

            }
         return d;
      }
      public String getAnswer() 
      {
         try
         {
            answer  = buffer.readLine(); 
         }
            catch (IOException e)
            {

            }
         return answer;
      }
      public String getHint() 
      {
         try
         {
            hint  = buffer.readLine(); 
         }
            catch (IOException e)
            {

            }
         return hint; 
      }
      public void resetBuffer () 
      {
         try
         {
            file.close(); 
            buffer.close(); 
            file = new FileReader("questions.txt"); 
            buffer = new BufferedReader(file); 
         }
            catch (IOException e)
            {
            }
      }
   }

