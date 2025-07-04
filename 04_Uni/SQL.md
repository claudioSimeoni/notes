## TYPES 

#### Numeric Types

- `INT` / `INTEGER`: Whole numbers, both positive and negative.
- `SMALLINT`: Smaller integer range, uses less storage.
- `BIGINT`: Very large integers.
- `DECIMAL(p, s)` / `NUMERIC(p, s)`: Fixed-point numbers with precision `p` and scale `s`.
- `FLOAT`: Approximate numeric type (floating point), less precise.
- `REAL`: Similar to `FLOAT`, precision may vary by DBMS.
- `DOUBLE` / `DOUBLE PRECISION`: Higher-precision floating point number.

---

#### Text Types

- `CHAR(n)`: Fixed-length string of `n` characters.
- `VARCHAR(n)`: Variable-length string up to `n` characters.
- `TEXT`: Long text data, size may depend on DBMS.

---

#### Date and Time Types

- `DATE`: Stores only the date (e.g., `YYYY-MM-DD`).
- `TIME`: Stores only the time (e.g., `HH:MM:SS`).
- `DATETIME`: Stores both date and time.
- `TIMESTAMP`: Similar to `DATETIME`, often includes time zone or auto-update behavior.
- `YEAR`: Stores only the year (MySQL-specific).

---

#### Boolean / Logical Types

- `BOOLEAN`: `TRUE` or `FALSE`.
- `BIT`: Binary storage, typically 0 or 1.

---

## DATA MANIPULATION

#### Creating stuff  

In SQL, create schema creates a subset of the db while in MYSQL it is the same of creating a database. 

```sql
CREATE DATABASE nome_database; 

CREATE TABLE nome_tabella (
  nome_colonna tipo [DEFAULT valore] [vincolo]
);

CREATE TABLE Utente (
  id INT, 
  nome VARCHAR(50),
  eta INT 
);
```

In sql you can also create new domains 

---

#### Intrarelational constraints 

```sql
CREATE TABLE Utente (
  id INT NOT NULL, // this ensures that id is never null 
  nome VARCHAR(50),
  eta INT DEFAULT 18, 
  email VARCHAR(100) UNIQUE  // ensures the unique occurrence
  stipendio DECIMAL(10, 2) CHECK (stipendio >= 0) // adds a condition
);

CREATE TABLE Prodotto (
  id INT PRIMARY KEY, // uniqueness + not null (becomes primary key)
  nome VARCHAR(100)

 // if you want more than one attribute you can do 
 // PRIMARY KEY (id, nome) at the end of the list 
 // this also works with unique 
);
```

---

#### Interrelational constraints 

You must ensure that the attribute you are referring is a primary key. 

```sql
CREATE TABLE Ordine (
  id INT PRIMARY KEY,
  cliente_id INT,
  FOREIGN KEY (cliente_id) // vincolo di integrità referenziale 
    REFERENCES Cliente(id)
    ON DELETE CASCADE   // Se un cliente viene eliminato, gli ordini del 
    // cliente vengono eliminati
    ON UPDATE CASCADE   // Se l id cliente viene aggiornato, l id cliente 
    // negli ordini viene aggiornato
);

CREATE TABLE Ordine (
  id INT REFERENCES Cliente(id), // posso farlo anche su un solo attributo 
  cliente_id INT,
  FOREIGN KEY (cliente_id) 
    REFERENCES Cliente(id)
    ON DELETE SET NULL   // Se il cliente viene eliminato, 
    // cliente_id diventa NULL
    ON UPDATE SET NULL   // Se l id cliente cambia, 
    // cliente_id diventa NULL
);

CREATE TABLE Ordine (
  id INT PRIMARY KEY,
  cliente_id INT,
  FOREIGN KEY (cliente_id) 
    REFERENCES Cliente(id)
    ON DELETE RESTRICT   // Impedisce l eliminazione se ci 
    // sono ordini associati
    ON UPDATE RESTRICT   // Impedisce l aggiornamento se ci 
    // sono ordini associati
);
```

---

#### Altering the columns 

You can do a lot of things not mentioned here because there are too many of them. 

```sql
RENAME DATABASE vecchio_nome TO nuovo_nome;

// adding or removing a column
ALTER TABLE Cliente ADD COLUMN email VARCHAR(100) UNIQUE;
ALTER TABLE nome_tabella DROP COLUMN nome_colonna;
```

---

#### Altering the rows 

```sql
// updating
UPDATE Clienti
SET Stato = 'Attivo'
WHERE UltimoAccesso < '2025-01-01';

UPDATE Ordini
JOIN Clienti ON Ordini.ClienteID = Clienti.ID
SET Ordini.Sconto = 0.05
WHERE Clienti.Città = 'Napoli';

// inserting 
INSERT INTO Visita(Medico, Paziente, Data)
        VALUES (010, ‘slq6’, CURRENT_DATE - INTERVAL 3 DAY);

INSERT INTO Paziente // if I set a value for ALL the columns 
        VALUES (‘Passerotti’, ‘Elvira’, ‘1965-10-27’, ‘Pisa’, 1500);

INSERT INTO Tabella [(Attributo1, Attributo2,...,AttributoN)]
Query_di_selezione // here the query is on another table, clearly the
// attributes returned by the query must have the same types required 


// deleting
DELETE FROM Users WHERE ID = 1;
```

Update and Delete can sometimes cause problems: if the condition contains directly the table itself the DMBS doesn't know which thing to do first, so you can solve by both **nesting the query into a select (*)** and using a join. 

---

It exists a special schema with information on the db named INFORMATION_SCHEMA.

## QUERIES 

#### Unusual Things  

- Returning generic expression made with the attributes.

```sql
SELECT Età / 12
FROM Persona
WHERE Età BETWEEN 45 AND 60;
```

- Rename any attribute or table in the SELECT / FROM: 

```sql
SELECT Età AS E 
FROM Persona P 
WHERE Età BETWEEN 45 AND 60;
// both ways are correct, in the select we typically prefer AS 
```

- Operator LIKE: the first operand is an attribute while the second one is something of this form 'ahs_shaug%' where any _ rappresents a generic character while % a generic string. 
  
- NULL works in a specific strange way: 
1. When involved in any arithmetic operation or comparison like >, = ... it returns NULL. 
2. In aggregate operators it is considered only whit **COUNT(*)**
3. When involved in logical operations it behaves like a false. 
4. You can handle NULL values with functions like 


#### BETWEEN E DISTINCT

```sql
SELECT DISTINCT Cognome, Nome, Età
FROM Persona
WHERE Età BETWEEN 45 AND 60;
```

---

#### DATE_FORMAT

%Y anno (4 cifre)
%y anno (2 cifre)
%M nome del mese  
%m mese (2 cifre)
%d giorno del mese (00-31)
%W nome del giorno
%w giorno della settimana {0,...,6}
%T orario (hh:mm:ss)

```sql
SELECT Matricola, DATE_FORMAT(DataLaurea, ‘%d|%m|%Y, %W’)
FROM Studente
WHERE DataIscrizione < ‘2005-01-01’;
```

---

#### DAY, MONTH, YEAR (Data)

Returns in digits the day, month or year of a date. 

```sql
SELECT Matricola, MONTH(DataLaurea)
FROM Studente
WHERE DataLaurea IS NOT NULL
        AND YEAR(DataIscrizione) > Year(CURRENT_DATE); 
```

---

#### DATEDIFF(Data 1, Data 2) and INTERVAL 

Interval is is a period you can add or subtract from a date both with + and - or with DATE_ADD() and DATE_SUB(), DATEDIFF() returns the difference in days between two dates. 


```sql
SELECT Matricola, MONTH(DataIscrizione)
FROM Studente
WHERE DataLaurea = DATE_ADD(DataIscrizione, INTERVAL 
        5 YEAR);

        // oppure DataIscrizione + INTERVAL 5 YEAR 
        //                       + INTERVAL 4 MONTH 
        //                       + INTERVAL 6 DAY
```

---

#### PERIOD_DIFF

Returns the difference in months between two dates expressed in the format yyyymm.

```sql
PERIOD_DIFF(DATE_FORMAT(DataLaurea,'%Y%m'),
                DATE_FORMAT(DataIscrizione, '%Y%m'))
```

---

#### Aggregation operators 

COUNT(attributes) can be used to count the dimension of the relation generated by a query.

```sql
SELECT COUNT(*) 
// optional: AS GivenName (note that this can be done always)
FROM stocazzo 
WHERE length > 20; 
```

SUM(attributes), AVG(attributes), MAX(attributes), MIN(attributes), these functions work exactly as the previous ones. I guess other functions like these exists, every time i find one I'll add it here: STDDEV() computes the standard deviation of some values. 

---

#### NATURAL JOIN, CROSS JOIN, INNER (Theta) JOIN, LEFT, RIGHT and FULL

ON condition is used as the condition of the join and is supported only by inner, left, right and full. Where is used as a selection after the query table is built. Here you can also see an example of the function COUNT: this query returns the number of distinct values of the query. 

```sql
SELECT COUNT(DISTINCT P.Nome)
        FROM PAZIENTE P 
        CROSS JOIN
        medico m WHERE P.Nome = m.Nome; 
```

```sql
SELECT DISTINCT P.Nome
        FROM PAZIENTE P 
        INNER JOIN // or LEFT(RIGHT) OUTER JOIN OR FULL JOIN
        medico m ON P.Nome = m.Nome; 
```
 
Another interesting thing is that you can use Derived tables inside queries as such: 

```sql
SELECT DISTINCT V1.Medico
        FROM Visita V1 LEFT OUTER JOIN
        (
        SELECT V2.Medico // Derived table
                FROM Visita V2
        WHERE DAYOFWEEK(V2.Data) = 4
        ) AS D
        ON V1.Medico = D.Medico
WHERE D.Medico IS NULL;
```

---

#### GROUP BY 

GROUP BY is used to "compress" each value of a certain attribute to a single row according to an aggregation operation. 

```sql 
SELECT Specializzazione, AVG(Parcella) AS ParcellaMedia
FROM Medico
GROUP BY Specializzazione;
```

What GROUP BY actually does is that he builds the tables according to the condition, by grouping records with the same Specializzazione, then it checks eventual conditions with HAVING (used in the following example), and then it compresses all the records of the tables according to the aggregation operator on the top. (Note that HAVING needs an aggregation operator). 

```sql
SELECT Specializzazione
FROM Medico
GROUP BY Specializzazione
HAVING COUNT(*) > 2;
```

---

#### ORDER BY and LIMIT

```sql
SELECT * FROM tabella
ORDER BY colonna1 [ASC | DESC], colonna2 [ASC | DESC], ...;

// here asc and desc mean ascendent and descendent, clearly the 
// second parameter is necessary if the first one is equal and so on
```

**LIMIT 20** exactly after a query will return only the first 20 records. 

--- 

#### WITH 

WITH is quite simple, it is used to pre-build tables that we will use then in the query, the syntax is the following: 

```sql
WITH
        name1 AS (query1)
        ,
        name2 AS (query2)
        ,
        ...
        ,
        nameN AS (queryN)
query finale; 
```

---

#### SUBQUERY and IN 

As we saw before you can make subqueries to use in joins, these subqueries can also be used to check if a certain record is somewhere in the table resulting from it. You can see this in the following example. 

- Every subquery query has an equivalent **join query**. 
- A nested subquery can "see" everything outside it, the reciprocal is not true. 
- If a subquery returns a single record with a **single attribute** (scalar query) it can be used as an argument of comparing operators. 


```sql 
SELECT DISTINCT P.Cognome
FROM Paziente P
WHERE P.Cognome NOT IN ( // you can also use IN 
                        SELECT M.Cognome
                        FROM Medico M
                        );
```

A **correlated subquery** is a query that refers to attribute outside itself, in this case the query is executed separately for every record of the outside query: 

```sql
SELECT DISTINCT V1.Medico
FROM Visita V1
WHERE YEAR(V1.Data) = 2013
        AND MONTH(V1.Data) = 10
        AND V1.Paziente NOT IN ( SELECT V2.Paziente
                                 FROM Visita V2
                                 WHERE V2.Medico = V1.Medico
                                 AND V2.Data < V1.Data )

// you can also use it inside the select

SELECT P.CodiceFiscale,(SELECT COUNT(*)
                        FROM Visita V
                        WHERE V.Paziente = P.CodFiscale) AS TotVis
FROM Paziente AS P
WHERE Sesso = ‘M’
```

#### EXISTS and ALL 

**Exists** is used to find out if a subquery contains at least one record, while **All** is used to check for example if a certain number x is bigger than any record in a column table. 

```sql

SELECT V1.Medico, V1.Paziente, V1.Data
FROM Visita V1
WHERE MONTH(V1.Data) = 1
        AND YEAR(V1.Data) = 2016
        AND EXISTS // NOT EXISTS
        (
        SELECT *
        FROM Visita V2
        WHERE V2.Medico = V1.Medico
                AND V2.Paziente = V1.Paziente
                AND V2.Data < V1.Data
        );
```

#### DIVISION

Given two attributes A and B, the division A / B means finding every value of A that is associated with all the possible values of B, the easiest way to do so is the following: 

```sql
SELECT V.Paziente 
FROM Visita V
GROUP BY V.Paziente 
HAVING COUNT(DISTINCT V.Medico) = (SELECT COUNT(*)
                                   FROM Medico); 
```

#### SETS operators 

```sql
query 1 // will return attr1, attr2 ... attrn
intersect/union/except // the last one is like the - 
query 2 // will return bttr1, bttr2 ... bttrn 

// returns the attributes of the first query and then 
// it applyes the operator on the i-th a and i-th b. 
```

---
## ADVANCED SQL 

#### CHECK and ASSERTION 

Check is an alternative way to add constraints to the db. Inside a check condition you can also refer to other tables. Even though it is very useful, when using CHECK you cannot react to wrong insertions in a specific way, in general it is preferred to use traditional constraints when possible. 

```sql
CREATE TABLE Impiegato (
  ID INT PRIMARY KEY,
  Nome VARCHAR(50) NOT NULL,
  Eta INT CHECK (Eta >= 18),                 -- Inline CHECK: age must be 18+
  Stipendio DECIMAL(10,2),
  Dipartimento VARCHAR(30),
  
  -- Table-level CHECK: rule combining multiple attributes
  CHECK (Dipartimento != 'HR' OR Stipendio >= 3000)
);
```

An assertion is a check on the whole db, create assertion Nome check Condizione. 

#### STORED PROCEDURE 

A stored procedure is a declarative-procedural program stored in the DBMS. It is used for **security purposes**: when you don't want somebody to have access to the architecture of your database while still being able to query what he needs. It is also used to **avoid redundance** of writing many times the same query. In addition the stored procedure remains **compiled**.  

```sql
DROP PROCEDURE IF EXISTS mostra_specializzazioni;

DELIMITER $$

// body 
CREATE PROCEDURE mostra_specializzazioni()
BEGIN

// variables 
// Puoi assegnare un valore usando SET o SELECT + INTO 
DECLARE variableName INT DEFAULT 0; 
SET @diomerda = 5; 
// the @ variables are global variables, while the declare one are 
// local, you can define a global variable everywhere, another 
// important fact is that OUT variables passed by the user must 
// be global because the body must be able to see them. 

SELECT DISTINCT Specializzazione
FROM Medico;
END $$

DELIMITER; 

// per chiamarla CALL mostra_specializzazioni(); 
```

It almost works like traditional programming, you have variables, loops etc.

---

#### PARAMETERS

```sql 
DROP PROCEDURE IF EXISTS tot_pazienti_visitati_spec;

DELIMITER $$
CREATE PROCEDURE tot_pazienti_visitati_spec(
                        IN _specializzazione VARCHAR(100),
                        OUT totale_pazienti_ INT) // also INOUT
BEGIN
SELECT COUNT(DISTINCT V.Paziente) INTO totale_pazienti_
FROM Visita V
        INNER JOIN
        Medico M ON V.Medico = M.Matricola
WHERE M.Specializzazione = _specializzazione;
END $$

DELIMITER ;

CALL tot_pazienti_visitati_spec(‘Neurologia’, @quantiPazienti);
SELECT @quantiPazienti;

// out variables needs to be tagged with a @
```

---

#### IF , CASE and LOOPS  

```sql
IF if_condition THEN
-- blocco istruzioni if true
ELSEIF elseif_1_condition THEN
-- blocco istruzioni elseif_1
ELSEIF elseif_N_condition THEN
-- blocco istruzioni elseif_N
ELSE
-- blocco istruzioni else
END IF ;


CASE
WHEN condition_1 THEN
..
.
-- blocco istruzioni_1
WHEN condition_N THEN
-- blocco istruzioni_N
END CASE ;


WHILE condition DO
-- blocco istruzioni
END WHILE;


REPEAT
-- blocco istruzioni
UNTIL condition
END REPEAT;


loop_label: LOOP
-- blocco istruzioni e check di condizioni

ITERATE loop_label; // is like continue 
LEAVE loop_lable; // is like break
END LOOP;
// labels allow to quit extern loops if you are in a nested one 
```

#### CURSORS 

A cursor is an iterator over a table that is the result of a query. 

```sql
// Variables where to put the current values we are traversing 
DECLARE done INT DEFAULT 0;   // this is a flag set to one when 
// the cursor reaches the end of the table
DECLARE var1 INT;                   
DECLARE var2 VARCHAR(100);    

// this query is not executed immediately, it is just prepared 
DECLARE mio_cursore CURSOR FOR
    SELECT id, nome FROM Utenti;

// when you arrive to the end of the query done is set to one 
DECLARE CONTINUE HANDLER FOR NOT FOUND SET done = 1;


OPEN mio_cursore;

read_loop: LOOP
    FETCH mio_cursore INTO var1, var2;  

    IF done THEN
        LEAVE read_loop;                
    END IF;

    // here you do what you want to do
END LOOP;

CLOSE mio_cursore;
```

#### TRIGGERS

They simply "trigger" some function if a certain condition occurs, it can both be some DML query or some time condition. They are typically used to **avoid redundance** or **handling constraints**.

```sql
DROP TRIGGER IF EXISTS nome_trigger;
CREATE TRIGGER nome_trigger
[BEFORE | AFTER] [INSERT | UPDATE | DELETE] ON Tabella
// these are the conditions that will trigger the trigger and tell it 
// when to act 
FOR EACH ROW // inserted
blocco_istruzioni

// examples 
DELIMITER $$

CREATE TRIGGER trg_utenti_delete
BEFORE DELETE ON utenti
FOR EACH ROW
BEGIN
  INSERT INTO utenti_deleted_log (id, nome)
  VALUES (OLD.id, OLD.nome);
END$$

DELIMITER ;


DROP TRIGGER IF EXISTS aggiorna_ultima_visita;
DELIMITER $$

CREATE TRIGGER aggiorna_ultima_visita
AFTER INSERT ON Visita
FOR EACH ROW
BEGIN
  UPDATE Paziente
  SET UltimaVisita = CURRENT_DATE
  WHERE CodFiscale = NEW.Paziente; // here new is like the "this" in 
// a class: it refers to the current record
END$$

DELIMITER ;
```

## VIEWS 

#### Materialized 

You need to actually build those tables and then use triggers to handle them. 

*** // missing this part on virtual ones ***

---
## Window Functions 
 
They put beside any record r a value obtained from an operation executed on a set of records that are logically linked. You can apply OVER() to any aggregation function (or other types of functions listed later). 

```sql
SELECT M.Matricola, 
        M.Dio
        M.Porco
        AVG(M.Parcella) OVER(
                            PARTITION BY M.Specializzazione
                            ) // senza clausola applica avg
                              // su tutti i record 
FROM MEDICO M 
```

#### WINDOW FUNCTIONS NON AGGREGATE 

```sql
attributo ROW_NUMBER() OVER([PARTITION BY attributo]) 

attributo RANK() OVER([PARTITION BY attributo][ORDER BY attributo])
// also DENSE_RANK()
```

#### Transactions 

```sql
begin; 
action1; 
actionn; 
commit; 

// you can also use if statements and if something goes wrong 
// instead of commit you use rollback that undo everything 
```

// begin and end are required in compound statements while delimiter is only mysql to avoid that the first ; ends the whole group of operations. 

## Coalesce, ifnull, case

CASE creates a new attribute based on an if condition 

```sql
SELECT nome,
       voto,
       CASE
         WHEN voto >= 90 THEN 'Eccellente'
         WHEN voto >= 75 THEN 'Buono'
         WHEN voto >= 60 THEN 'Sufficiente'
         ELSE 'Insufficiente'
       END AS valutazione
FROM studenti;
```

COALESCE(atrr1, attr2, attr3), returns the first not null value, i could also use a default value x as an argument so that if all the attributes before x are null you will use x in place of null. 

```sql
SELECT nome,
       COALESCE(email_personale, email_ufficio, 'Nessuna email') AS email_preferita
FROM dipendenti;

Qui COALESCE restituisce il primo valore non NULL tra quelli dati.
```

IFNULL(attr, default_value) substitutes every nulll in attr with def. 

```sql
SELECT nome,
       IFNULL(email_personale, 'Nessuna email') AS email_personale
FROM dipendenti;
```