import java.util.Scanner;

public class Customer{
    private String customerName;
    private long contactNumber;
    private String emailId;
    private int age;
    public Customer(){

    }
    public String getCustomerName(){
        return this.customerName;
    }
    public void setCustomerName(String customerName){
        this.customerName = customerName;
    }
    public long getContactNumber(){
        return this.contactNumber;
    }
    public void setContactNumber(long contactNumber){
        this.contactNumber = contactNumber;
    }
    public String getEmailId(){
        return this.emailId;
    }
    public void setEmailId(String emailId){
        this.emailId = emailId;
    }
    public int getAge(){
        return this.age;
    }
    public void setAge(int age){
        this.age = age;
    }
    public static void main(String[] args){
        Customer customer = new Customer();
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the Name: ");
        String name = scan.next();
        customer.setCustomerName(name);
        System.out.println("Enter the ContactNumber: ");
        long contact = scan.nextLong();
        customer.setContactNumber(contact);
        System.out.println("Enter the EmailId: ");
        String email = scan.next();
        customer.setEmailId(email);
        System.out.print("Age:");
        int age = scan.nextInt();
        customer.setAge(age);

        System.out.println("Name:" + customer.getCustomerName());
        System.out.println("ContactNumber:" + customer.getContactNumber());
        System.out.println("EmailId:" + customer.getEmailId());
        System.out.println("Age:" + customer.getAge());
    }
}
