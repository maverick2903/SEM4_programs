class Movie extends Thread
{
    int vacancy=2,req;
    Movie(int x)
    {
        req=x;
    }
    public synchronized void run()
    {
        if(req<=vacancy)
        {
            System.out.println("Tickets are booked for "+Thread.currentThread().getName()+"\n");
            try
            {
                Thread.sleep(100);
            }
            catch(Exception e){}
            vacancy = vacancy - req;
            }
        else
        {
            System.out.println("Housefull "+Thread.currentThread().getName()+"\n");
        }
    }
}

class Main
{
    public static void main(String z[])
    {
        Movie m=new Movie(1);
        Thread t1 = new Thread(m);
              Thread t2 = new Thread(m);
              Thread t3 = new Thread(m);
              Thread t4 = new Thread(m);
              t1.setName("Person 1 ");
              t2.setName("Person 2");
              t3.setName("Person 3");
              t4.setName("Person 4");
              t1.start();
              t2.start();
              t3.start();
              t4.start();
    }
}
