
import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Scanner;

class Main 
{
	ArrayList<Customer> custList = new ArrayList<>();
	public void fetchData()
	{
		try
		{
			FileReader fr = new FileReader("data.txt");
			BufferedReader bf = new BufferedReader(fr);
			
			while(bf!=null)
			{
                // System.out.println(bf.readLine());
				String[] s = bf.readLine().split(" ");
				custList.add(new Customer(Integer.valueOf(s[0]),s[1],s[2],Long.valueOf(s[3]),s[4]));
			}
			bf.close();
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}
	
	public void display()
	{
		int i=1;
		for(Customer c:custList)
		{
			System.out.println("-----Customer Details-----");
			System.out.println("Record"+(i++));
			System.out.println("CustomeId : "+c.custId+"\nCustomerName : "+c.custName+"\nAccountNo : "+c.accNo+"\nBalance : "+c.balance+"\nPassword : "+c.password);
			
		}
	}
	
	public static void main(String args[])
	{
		Scanner x = new Scanner(System.in);
		Main m = new Main();
		m.fetchData(); 
		while(true)
		{
		    System.out.println("Enter your choice:\n1.Display records\n2.Add customer\n3.exit");
			switch(x.nextInt())
			{
			case 1:m.display();break;
			case 2:break;
			case 3:x.close();System.exit(0);
					
			}
		}
		
		
	}

}


//customer class


class Customer 
{
	public int custId;
	public String custName;
	public String accNo;
	public long balance;
	public String password;
	
	public Customer(int custId,String custName,String accNo,long balance,String password)
	{
		this.custId = custId;
		this.custName = custName;
		this.accNo = accNo;
		this.balance = balance;
		this.password = password;
	}
}
