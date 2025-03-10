







#include <iostream>
#include <windows.h>
#include <mysql.h>


using namespace std;

int main() {
    MYSQL* conn;

    // Initialize MySQL connection
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, "localhost", "root", "", "Residential Society Management System", 3307, NULL, 0);

    if (conn) {
        // Create Society Table
        string query_create_society = "CREATE TABLE IF NOT EXISTS Society ("
                                      "S_name VARCHAR(50) PRIMARY KEY, "
                                      "Manager VARCHAR(50) NOT NULL, "
                                      "Pincode INT CHECK (Pincode BETWEEN 100000 AND 999999), "
                                      "Sector INT CHECK (Sector BETWEEN 1 AND 150), "
                                      "City VARCHAR(50) NOT NULL);";

        if (mysql_query(conn, query_create_society.c_str())) {
            cout << "Error executing query for Society table: " << mysql_error(conn) << endl;
        } else {
            cout << "Society Table created." << endl;
        }

        // Create Owner Table
        string query_create_owner = "CREATE TABLE IF NOT EXISTS Owner ("
                                    "O_id INT PRIMARY KEY AUTO_INCREMENT, "
                                    "O_name VARCHAR(50) NOT NULL, "
                                    "O_phone VARCHAR(10) UNIQUE NOT NULL CHECK (O_phone REGEXP '^[0-9]{10}$'), "
                                    "O_ID_proof VARCHAR(12) CHECK (O_ID_proof REGEXP '^[0-9]{12}$'), "
                                    "Date_of_Buying DATE NOT NULL CHECK (Date_of_Buying >= '2000-01-01'), "
                                    "O_email VARCHAR(50) UNIQUE);";

        if (mysql_query(conn, query_create_owner.c_str())) {
            cout << "Error executing query for Owner table: " << mysql_error(conn) << endl;
        } else {
            cout << "Owner Table created." << endl;
        }

        // Create Apartment Table
        string query_create_apartment = "CREATE TABLE IF NOT EXISTS Apartment ("
                                        "A_id INT PRIMARY KEY, "
                                        "A_type ENUM('1BHK', '2BHK', '3BHK') NOT NULL, "
                                        "A_maintenance DOUBLE NOT NULL CHECK (A_maintenance > 0), "
                                        "S_name VARCHAR(50) NOT NULL, "
                                        "A_tower VARCHAR(1) NOT NULL, "
                                        "O_id INT NOT NULL, "
                                        "A_cost DOUBLE NOT NULL CHECK (A_cost > 0), "
                                        "FOREIGN KEY (S_name) REFERENCES Society(S_name) ON DELETE CASCADE, "
                                        "FOREIGN KEY (O_id) REFERENCES Owner(O_id) ON DELETE CASCADE);";

        if (mysql_query(conn, query_create_apartment.c_str())) {
            cout << "Error executing query for Apartment table: " << mysql_error(conn) << endl;
        } else {
            cout << "Apartment Table created." << endl;
        }

        // Create Tenant Table
        string query_create_tenants = "CREATE TABLE IF NOT EXISTS Tenant ("
                                      "T_id INT PRIMARY KEY AUTO_INCREMENT, "
                                      "T_name VARCHAR(50) NOT NULL, "
                                      "T_phone VARCHAR(10) UNIQUE NOT NULL CHECK (T_phone REGEXP '^[0-9]{10}$'), "
                                      "T_ID_proof VARCHAR(12) CHECK (T_ID_proof REGEXP '^[0-9]{12}$'), "
                                      "Rent DOUBLE CHECK (Rent > 0), "
                                      "O_id INT NOT NULL, "
                                      "A_id INT NOT NULL, "
                                      "Date_of_Renting DATE NOT NULL CHECK (Date_of_Renting >= '2000-01-01'), "
                                      "FOREIGN KEY (O_id) REFERENCES Owner(O_id) ON DELETE CASCADE, "
                                      "FOREIGN KEY (A_id) REFERENCES Apartment(A_id) ON DELETE CASCADE);";

        if (mysql_query(conn, query_create_tenants.c_str())) {
            cout << "Error executing query for Tenants table: " << mysql_error(conn) << endl;
        } else {
            cout << "Tenants Table created." << endl;
        }


      string query_create_complaints = "CREATE TABLE IF NOT EXISTS Complaint ("
                      "C_id INT PRIMARY KEY AUTO_INCREMENT, "
                      "Status ENUM('Pending', 'Completed') NOT NULL, "
                      "C_date DATE NOT NULL CHECK (C_date >= '2000-01-01'), "
                      "A_id INT NOT NULL, "
                      "FOREIGN KEY (A_id) REFERENCES Apartment(A_id) ON DELETE CASCADE);";

        if (mysql_query(conn, query_create_complaints.c_str())) {
            cout << "Error executing query for Complaints table: " << mysql_error(conn) << endl;
        } else {
            cout << "Complaints Table created." << endl;
        }

         string query_create_electrical="CREATE TABLE IF NOT EXISTS Electrical ("
                      "E_id INT PRIMARY KEY, "
                      "E_name VARCHAR(50) NOT NULL, "
                      "E_phone VARCHAR(10) UNIQUE NOT NULL CHECK (E_phone REGEXP '^[0-9]{10}$'));";
            if (mysql_query(conn, query_create_electrical.c_str())) {
            cout << "Error executing query for Electrical table: " << mysql_error(conn) << endl;
        } else {
            cout << "Electrical Table created." << endl;
        }
         string query_create_carpentry="CREATE TABLE IF NOT EXISTS Carpentry ("
                      "C_id INT PRIMARY KEY, "
                      "C_name VARCHAR(50) NOT NULL, "
                      "C_phone VARCHAR(10) UNIQUE NOT NULL CHECK (C_phone REGEXP '^[0-9]{10}$'));";

          if (mysql_query(conn, query_create_carpentry.c_str())) {
            cout << "Error executing query for Carpentry table: " << mysql_error(conn) << endl;
        } else {
            cout << "Carpentry Table created." << endl;
        }
         string query_create_plumbing="CREATE TABLE IF NOT EXISTS Plumbing ("
                      "P_id INT PRIMARY KEY, "
                      "P_name VARCHAR(50) NOT NULL, "
                      "P_phone VARCHAR(10) UNIQUE NOT NULL CHECK (P_phone REGEXP '^[0-9]{10}$'))";
        if (mysql_query(conn, query_create_plumbing.c_str())) {
            cout << "Error executing query for Plumbing table: " << mysql_error(conn) << endl;
        } else {
            cout << "Plumbing Table created." << endl;
        }
        string query_create_visitor= "CREATE TABLE IF NOT EXISTS Visitor ("
                      "V_id INT PRIMARY KEY AUTO_INCREMENT, "
                      "V_phone VARCHAR(10) UNIQUE NOT NULL CHECK (V_phone REGEXP '^[0-9]{10}$'), "
                      "V_ID_proof VARCHAR(12) CHECK (V_ID_proof REGEXP '^[0-9]{12}$'), "
                      "In_time TIME NOT NULL, "
                      "Out_time TIME NOT NULL, "
                      "A_id INT NOT NULL, "
                      "FOREIGN KEY (A_id) REFERENCES Apartment(A_id) ON DELETE CASCADE);";
            if (mysql_query(conn, query_create_visitor.c_str())) {
            cout << "Error executing query for Visitor table: " << mysql_error(conn) << endl;
        } else {
            cout << "Visitor Table created." << endl;
        }
      string query_create_visits = "CREATE TABLE IF NOT EXISTS Visits ("
                             "V_id INT PRIMARY KEY AUTO_INCREMENT, "
                             "V_date DATE NOT NULL CHECK (V_date >= '2000-01-01'), "
                             "S_name VARCHAR(50) NOT NULL, "
                             "FOREIGN KEY (S_name) REFERENCES Society(S_name) ON DELETE CASCADE);";

            if (mysql_query(conn, query_create_visits.c_str())) {
            cout << "Error executing query for Visits table: " << mysql_error(conn) << endl;
        } else {
            cout << "Visits Table created." << endl;
        }

          string query_insert_society = "INSERT INTO Society (S_name, Manager, Pincode, Sector, City) VALUES "
                                      "('Sunshine Society', 'John Doe', 110011, 45, 'Delhi'), "
                                      "('Green Valley', 'Jane Smith', 122005, 30, 'Mumbai'), "
                                      "('Blue Ridge', 'Peter Pan', 560034, 12, 'Bangalore');";
        if (mysql_query(conn, query_insert_society.c_str())) {
            cout << "Error inserting data into Society table: " << mysql_error(conn) << endl;
        } else {
            cout << "Data inserted into Society table." << endl;
        }

        // Insert data into Owner table
        string query_insert_owner = "INSERT INTO Owner (O_name, O_phone, O_ID_proof, Date_of_Buying, O_email) VALUES "
                                    "('Alice Smith', '9876543210', '123456789012', '2020-05-15', 'alice@example.com'), "
                                    "('Bob Johnson', '9123456789', '987654321013', '2021-08-25', 'bob@example.com'), "
                                    "('Carol White', '9345678901', '987654321014', '2022-11-01', 'carol@example.com');";
        if (mysql_query(conn, query_insert_owner.c_str())) {
            cout << "Error inserting data into Owner table: " << mysql_error(conn) << endl;
        } else {
            cout << "Data inserted into Owner table." << endl;
        }

        // Insert data into Apartment table
        string query_insert_apartment = "INSERT INTO Apartment (A_id, A_type, A_maintenance, S_name, A_tower, O_id, A_cost) VALUES "
                                        "(101, '2BHK', 1500.50, 'Sunshine Society', 'A', 1, 4500000.00), "
                                        "(102, '1BHK', 1200.00, 'Green Valley', 'B', 2, 3000000.00), "
                                        "(103, '3BHK', 2000.75, 'Blue Ridge', 'C', 3, 6000000.00);";
        if (mysql_query(conn, query_insert_apartment.c_str())) {
            cout << "Error inserting data into Apartment table: " << mysql_error(conn) << endl;
        } else {
            cout << "Data inserted into Apartment table." << endl;
        }

        // Insert data into Tenant table
        string query_insert_tenant = "INSERT INTO Tenant (T_name, T_phone, T_ID_proof, Rent, O_id, A_id, Date_of_Renting) VALUES "
                                     "('Bob Johnson', '9123456789', '987654321012', 20000.00, 1, 101, '2022-03-01'), "
                                     "('Alice Brown', '9654321987', '123456789013', 25000.00, 2, 102, '2022-05-15'), "
                                     "('Carol Green', '9345678765', '987654321015', 30000.00, 3, 103, '2023-08-20');";
        if (mysql_query(conn, query_insert_tenant.c_str())) {
            cout << "Error inserting data into Tenant table: " << mysql_error(conn) << endl;
        } else {
            cout << "Data inserted into Tenant table." << endl;
        }

        // Insert data into Complaint table
        string query_insert_complaint = "INSERT INTO Complaint (Status, C_date, A_id) VALUES "
                                        "('Pending', '2024-11-09', 101), "
                                        "('Completed', '2024-11-08', 102), "
                                        "('Pending', '2024-11-07', 103);";
        if (mysql_query(conn, query_insert_complaint.c_str())) {
            cout << "Error inserting data into Complaint table: " << mysql_error(conn) << endl;
        } else {
            cout << "Data inserted into Complaint table." << endl;
        }

        // Insert data into Electrical table
        string query_insert_electrical = "INSERT INTO Electrical (E_id, E_name, E_phone) VALUES "
                                        "(1, 'John Doe', '9876543210'), "
                                        "(2, 'Jane Smith', '9123456789'), "
                                        "(3, 'James Brown', '9345678901');";
        if (mysql_query(conn, query_insert_electrical.c_str())) {
            cout << "Error inserting data into Electrical table: " << mysql_error(conn) << endl;
        } else {
            cout << "Data inserted into Electrical table." << endl;
        }

        // Insert data into Carpentry table
        string query_insert_carpentry = "INSERT INTO Carpentry (C_id, C_name, C_phone) VALUES "
                                        "(1, 'David Lee', '9123456789'), "
                                        "(2, 'Emma White', '9345678901'), "
                                        "(3, 'Olivia Green', '9876543210');";
        if (mysql_query(conn, query_insert_carpentry.c_str())) {
            cout << "Error inserting data into Carpentry table: " << mysql_error(conn) << endl;
        } else {
            cout << "Data inserted into Carpentry table." << endl;
        }

        // Insert data into Plumbing table
        string query_insert_plumbing = "INSERT INTO Plumbing (P_id, P_name, P_phone) VALUES "
                                       "(1, 'Mason Hall', '9123456789'), "
                                       "(2, 'Lucas Scott', '9876543210'), "
                                       "(3, 'Liam Miller', '9345678901');";
        if (mysql_query(conn, query_insert_plumbing.c_str())) {
            cout << "Error inserting data into Plumbing table: " << mysql_error(conn) << endl;
        } else {
            cout << "Data inserted into Plumbing table." << endl;
        }

        // Insert data into Visitor table
        string query_insert_visitor = "INSERT INTO Visitor (V_phone, V_ID_proof, In_time, Out_time, A_id) VALUES "
                                      "('9912345678', '123456789012', '09:00:00', '10:00:00', 101), "
                                      "('9887654321', '987654321011', '11:00:00', '12:00:00', 102), "
                                      "('9876543210', '123456789013', '14:00:00', '15:00:00', 103);";
        if (mysql_query(conn, query_insert_visitor.c_str())) {
            cout << "Error inserting data into Visitor table: " << mysql_error(conn) << endl;
        } else {
            cout << "Data inserted into Visitor table." << endl;
        }

        // Insert data into Visits table
        string query_insert_visits = "INSERT INTO Visits (V_date, S_name) VALUES "
                                     "('2024-11-09', 'Sunshine Society'), "
                                     "('2024-11-09', 'Green Valley'), "
                                     "('2024-11-09', 'Blue Ridge');";
        if (mysql_query(conn, query_insert_visits.c_str())) {
            cout << "Error inserting data into Visits table: " << mysql_error(conn) << endl;
        } else {
            cout << "Data inserted into Visits table." << endl;
        }

}

 else {
        cout << "Error connecting to MySQL: " << mysql_error(conn) << endl;
    }


    mysql_close(conn); // Close the connection

    return 0;
}
