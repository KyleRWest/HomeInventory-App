using System.Data.SqlClient;

string connectionString = "Server=QUANDALE;Database=Inventory;User Id=WindowsAuthentication;";

namespace TableButtonFunctions
{
    using (SqlConnection connection = new SqlConnection(connectionString))
    {
        connection.Open();
        
        string commandText = "SELECT * FROM Inventory"; // Replace with your SQL command
        using (SqlCommand command = new SqlCommand(commandText, connection))
        {
            using (SqlDataReader reader = command.ExecuteReader())
            {
                while (reader.Read())
                {
                    Console.WriteLine($"Product ID: {reader["ProductID"]}, Name: {reader["ProductName"]}");
                }
            }
        }
    }
    public class TableButtonFunctions
    {
        using (SqlConnection connection = new SqlConnection(connectionString))
        {   
        connection.Open();

        string commandText = "SELECT * FROM Products"; // Replace with your SQL command
        using (SqlCommand command = new SqlCommand(commandText, connection))
        {
            using (SqlDataReader reader = command.ExecuteReader())
            {
                while (reader.Read())
                {
                    Console.WriteLine($"Product ID: {reader["ProductID"]}, Name: {reader["ProductName"]}");
                }
            }
        }
     }
public string CommandName { get; set; }
        public string CommandDescription { get; set; }
        public TableButtonFunctions(string commandName, string commandDescription)
        {
            CommandName = commandName;
            CommandDescription = commandDescription;
        }
        public void Execute()
        {
            Console.WriteLine($"Executing command: {CommandName}");
            // Add logic to execute the command
        }
    }
}