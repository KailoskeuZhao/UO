package TestGround;






public class lamdbaTest implements Say

{

    public static void main(String args[]){

     
        dudu(lamdbaTestIn1::ni);
        dudu(lamdbaTestIn1::bye);
        dudu(() -> System.out.println("wrongDirect"));

 

        

    }

    public void sa(){}

    public static void dudu(Say x){
        System.out.println("dudu");
        x.sa();
    }



}

