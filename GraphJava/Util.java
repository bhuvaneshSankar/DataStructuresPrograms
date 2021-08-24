import java.util.Set;
import java.util.HashSet;
import java.util.LinkedList;
public class Util{
    public Account createAccount(String name, int age, String sex){
        return new Account(name.toLowerCase(), age, sex.toLowerCase());
    }
    public static boolean addFriends(Account user, Account friend){
        if(user.addFriends(friend)==true) return true;
        else return false;
    }
    public static void main(String[] args){
        Util usr = new  Util();
        Account elon = usr.createAccount("elon", 25, "male");
        Account mark = usr.createAccount("mark", 24, "male");
        Account bill = usr.createAccount("bill", 21, "male");
        Account larry = usr.createAccount("larry", 21, "male");
        Account sergey = usr.createAccount("sergey", 21, "male");
        Account steve = usr.createAccount("steve", 21, "male");

        addFriends(elon, mark);
        addFriends(elon, larry);
        addFriends(mark, bill);
        addFriends(larry, sergey);
        addFriends(larry, mark);
        addFriends(bill, steve);

    //    Set<Account> friendlist = elon.getFriendList();
    //    for(Account o : friendlist){
    //        System.out.print(o.getName()+" ");
    //    }

        LinkedList<String> bfsPath = SearchAlgos.bfs(elon, steve);
        for(String name : bfsPath){
            System.out.print(name+" ");
        }


    }
}