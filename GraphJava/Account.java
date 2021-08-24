import java.util.Set;
import java.util.HashSet;
public class Account{
    String name;
    int age;
    String sex;
    Set<Account> friends;
    Account(String name, int age, String sex){
        this.name = name;
        this.age = age;
        this.sex = sex;
        friends = new HashSet<>();
    }
    public String getName(){
        return this.name;
    }
    public boolean addFriends(Account newFriend) throws IllegalArgumentException{
        if(newFriend == null) throw new IllegalArgumentException();
        if(friends.contains(newFriend)){
            return false;
        }
        else{
            friends.add(newFriend);
            return true;
        }
    }
    public Set<Account> getFriendList(){
        return this.friends;
    }
    public int hashCode(){
        return this.name.hashCode();
    }
}