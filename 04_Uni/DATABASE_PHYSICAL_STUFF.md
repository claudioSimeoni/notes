### Data Organization

Data is organized in the following way: you have **files**, each file occupies a memory **page** on the **mass memory**. Files are divided into three main categories: 

- **Log files**: they store everything is done on the database, they are mainly used to handle concurrency of transactions. 
- **Storage catalog**: they include table schema and generic **metadata** of the DB they store indexes of each table or information stored in the database, they also store **indexes**: basically the first access of the dbms to data is to these files. They are usually stored in B-trees. 
- **Data files**: they store the actual data of the db, the tables with their records. Each tables data can be stored in different files and inside a file data can be saved different ways: 
 
  - **Heap file**: no logic used to store data.
  - **Sorted file**: you can binary search. 
  - **Hashed file**: self-explanatory. 

The idea is that typically when you interact with the db, the **buffer** (an area of RAM used as a sort of cache) stores temporarily the recently accessed data and optimizes accesses to mass memory which costs so much.