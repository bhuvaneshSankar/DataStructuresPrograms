public class SortStack{
    public Stack<Integer> sort(Stack<Integer> s)        //two extra stack
	{
		//add code here.
		Stack<Integer> s1 = new Stack<>();
		Stack<Integer> s2 = new Stack<>();
		int size = s.size();
		for(int j=0; j<size && !(s.empty()); j++){
		    int val = s.pop();
		    s1.push(val);
		    for(int i=0; i<size && !(s.empty()); i++){
		        val = s.pop();
		        if(val<s1.peek()){
		            int temp = s1.pop();
		            s2.push(temp);
		            s1.push(val);
		        }
		        else{
		            s2.push(val);
		        }
		    }
		    while(!s2.empty()){
		        s.push(s2.pop());
		    }
		}
		return s1;
	}
    public Stack<Integer> sort(Stack<Integer> s){   //o(n*n)  one extra stack
        Stack<Integer> s1 = new Stack<>();
        int val = s.pop();
        s1.push(val);
        while(!s.empty()){
            val = s.pop();
            while(!s1.empty() && s1.peek()>val){            //insert the val in correct position(ascending order) in s1...till that pop s1 and push in s itself
                int elem = s1.pop();
                s.push(elem);
            }
            s1.push(val);
        }
        return s1;
    }
}