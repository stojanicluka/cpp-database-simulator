# cpp-database-simulator

**cpp-database-simulator** is a C++ application for executing SQL-like queries on a simulated database.

## Installation

The application can be built using any C++ compiler (eg. `g++`) by compiling and linking all .cpp source files:

```bash
g++ -o app *.cpp
```

## Usage

Users interact with the application using a command-line interface by choosing menu items and typing queries when prompted.

User can choose to create a new database or import one from a file.

Database limitations:
   - Only string data type is supported, written between single or double quotations marks
   - NULL values are not supported
   - Limited subset of SQL queries is implemented
   - There are no primary keys
   
Query syntax:
   - CREATE TABLE table_name ( column_list )  
	column_list = column_list , column_name  
	column_list = column_name
	
   - DROP TABLE table_name
   
   - SELECT selector FROM table_name [ WHERE condition_list ]  
	selector = * | column_list  
	condition_list = condition_list AND condition  
	condition_list = condition  
	condition = column_name = “value”  
	condition = column_name <> “value”
	
   - INSERT INTO table_name ( column_list ) VALUES record_list  
	record_list = record_list , record  
	record_list = record  
	record = ( value_list )  
	value_list = value_list , “value”  
	value_list = “value”
	
   - UPDATE table_name SET alteration_list WHERE condition_list  
	alteration_list = alteration_list , alteration  
	alteration_list = alteration  
	alteration = column_name = “value”
	
	
   - DELETE FROM table_name WHERE condition_list
   
   - SHOW TABLES

## Features

- Query execution
- Import/export database from/to SQL file
