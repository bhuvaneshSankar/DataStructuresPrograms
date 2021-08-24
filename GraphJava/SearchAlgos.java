import java.util.Set;
import java.util.LinkedHashSet;
import java.util.HashSet;
import java.util.Queue;
import java.util.LinkedList;
import java.util.HashMap;
public class SearchAlgos{
    public static LinkedList<String> bfs(Account start, Account dest){
        LinkedList<String> pathTraced = new LinkedList<>();
        Set<Account> visited = new HashSet<>();
        Queue<Account> q = new LinkedList<>();
        HashMap<String, String> parentMap= new HashMap<>();
        q.add(start);
        visited.add(start);
        boolean isFound=false;
        while(!q.isEmpty()){
            Account current = q.poll();
        //    System.out.println("name "+current.getName());
            visited.add(current);
            if(current.equals(dest)){
                isFound = true;
        //        System.out.println(current.getName());
                visited.add(current);
                break;
            }
            Set<Account> friends = current.getFriendList();
            System.out.println(friends.size());
            for(Account user : friends){
            //    System.out.println("friends " + user.getName());
                if(!visited.contains(user)){
                    q.add(user);
                    parentMap.put(user.getName(), current.getName());
                }
            }

        }
        if(isFound == true){
            pathTraced.addFirst(dest.getName());
            String curr = parentMap.get(dest.getName());
            while(!curr.equals(start.getName())){
                pathTraced.addFirst(curr);
                curr = parentMap.get(curr);
            }
            pathTraced.addFirst(start.getName());
        }
        return pathTraced;
    }
}