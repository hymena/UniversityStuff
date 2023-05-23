import psycopg2

# Update this part according to your own database!!!
connection = psycopg2.connect(database="19290337", user="postgres", password="1234", host="127.0.0.1", port="5432")

cursor = connection.cursor()

# This part is given as an example for the query of the first question. 
# For other questions, please add the necessary code pieces to the specified places!!!

# Question-1
print ('Question-1')
cursor.execute('''
    select order_id orderid,
    (unit_price*quantity) totalprice,
    (unit_price*quantity*(1-discount)) totalwithdiscountprice
    from "19290337_Project1".order_details
    order by totalwithdiscountprice desc, orderid asc
    limit 10 
''')

rows = cursor.fetchall()
print ('ORDERID\t\t TotalPrice\t\t TotalwithDiscountPrice')
for row in rows:
    print(str(row[0]).ljust(10) + " \t " + str(row[1]).ljust(20) + " \t " + str(row[2]).ljust(10))

# Question-2
print ('Question-2')

# Write your piece of code as in Question-1
cursor.execute('''
    (select shipped_date shippeddate,
    OD.order_id orderid,
    sum((unit_price*quantity)) totalprice,
    extract (year from shipped_date) as year
    from "19290337_Project1".order_details as OD,"19290337_Project1".orders O
    where(OD.order_id = O.order_id)
    and (shipped_date between '1997-12-30' and '1998-1-5')
    group by OD.order_id,shipped_date
    order by shipped_date asc, OD.order_id asc)
    union all
    (select shipped_date shippeddate,
    OD.order_id orderid,
    sum((unit_price*quantity)) totalprice,
    extract (year from shipped_date) as year
    from "19290337_Project1".order_details as OD,"19290337_Project1".orders O
    where(OD.order_id = O.order_id)
    and (shipped_date is null)
    group by OD.order_id,shipped_date
    having sum((unit_price*quantity)) > 4000
    order by shipped_date asc, OD.order_id asc)
''')
rows = cursor.fetchall()
print('shippdate\t orderid\t totalprice\t\t year')
for row in rows:
    print(str(row[0]).ljust(10) + " \t " + str(row[1]).ljust(10) + " \t " + str(row[2]).ljust(20) + " \t "+str(row[3]).ljust(10))

# Question-3
print ('Question-3')

# Write your piece of code as in Question-1

cursor.execute('''
    select category_name,
    Cat.category_id,
    product_name,
    product_id,
    unit_price,
    units_in_stock,
    units_on_order,
    reorder_level,
    discontinued
    from "19290337_Project1".categories as Cat
    join "19290337_Project1".products as Pro on Cat.category_id = Pro.category_id
    where (discontinued = 0 ) and (reorder_level > 20) and (units_on_order=0)
    order by product_id''')
print('category_name\t category_id\t product_id\t\t\t unit_price\t units_in_stock\t reorder_level\t discountinued')
rows = cursor.fetchall()
for row in rows:
    print(str(row[0]).ljust(10) + " \t " + str(row[1]).ljust(10) + " \t " + str(row[2]).ljust(30) + " \t "+str(row[3]).ljust(10) + " \t "+str(row[4]).ljust(10) + " \t "+str(row[5]).ljust(10)+ " \t "+str(row[6]).ljust(10))


# Question-4
print ('Question-4')

# Write your piece of code as in Question-1
cursor.execute('''
select ship_name,
ship_country,
Cus.customer_id,
Cus.company_name,
concat(first_name,' ',last_name) as salesperson,
S.phone phone,
Pro.product_id,
product_name,
freight
from "19290337_Project1".customers as Cus,"19290337_Project1".orders as O,"19290337_Project1".order_details as OD,"19290337_Project1".products as Pro,
"19290337_Project1".employees as E,"19290337_Project1".shippers as S
where(Cus.customer_id = O.customer_id)
and (O.order_id = OD.order_id)
and (OD.product_id = Pro.product_id)
and (E.employee_id = O.employee_id)
and (S.shipper_id = O.ship_via)
and (ship_country like '%y' and Cus.customer_id like 'M%' and freight>70)
order by ship_country desc, salesperson asc, freight asc, product_id asc ''')

rows = cursor.fetchall()
print('ship_name\t\t\t ship_country\t customer_id\t company_name\t\t\t\t salesperson\t\t phone\t\t product_id\t product_name\t\t freight')
for row in rows:
    print(str(row[0]).ljust(25) + " \t " + str(row[1]).ljust(10) + " \t " + str(row[2]).ljust(10) + " \t "+str(row[3]).ljust(25) + " \t "+str(row[4]).ljust(20) + " \t "+str(row[5]).ljust(20)+ " \t "+str(row[6]).ljust(5)+ " \t "+str(row[7]).ljust(25)+ " \t "+str(row[8]).ljust(10))

# Question-5
print ('Question-5')

# Write your piece of code as in Question-1

# Question-6
# Write your piece of code as in Question-1
print ('Question-6')
cursor.execute('''
(select table_name as tablename,
city,
company_name,
contact_name
from information_schema.tables,"19290337_Project1".customers
where table_name = 'customers' and contact_name like '%w%'
)
union all
(select table_name as tablename,
city,
company_name,
contact_name
from information_schema.tables,"19290337_Project1".suppliers
where table_name = 'suppliers' and contact_name like '%g%'
)
order by contact_name''')

rows = cursor.fetchall()
print('tablename\t\t city\t\t\t company_name\t\t\t contact_name')
for row in rows:
    print(str(row[0]).ljust(20) + " \t " + str(row[1]).ljust(15) + " \t " + str(row[2]).ljust(25) + " \t "+str(row[3]).ljust(15) )



# Question-7
print ('Question-7')

# Write your piece of code as in Question-1
cursor.execute('''
(select product_name as products_name,
unit_price
from "19290337_Project1".products
order by unit_price desc
limit 5)
union all
(select product_name as products_name,
unit_price
from "19290337_Project1".products
order by unit_price asc
limit 5)
order by unit_price desc''')
rows = cursor.fetchall()
print('products_name\t\t\t unit_price')
for row in rows:
    print(str(row[0]).ljust(25) + " \t " + str(row[1]) )


# Question-8
print ('Question-8')

# Write your piece of code as in Question-1

cursor.execute('''
with x as (
select extract (year from shipped_date) as shippedyear,
category_name,
sum(round((OD.unit_price*quantity*(1-discount))::numeric,2)) as categorysales
from "19290337_Project1".orders as O,"19290337_Project1".order_details as OD,
"19290337_Project1".products as P,"19290337_Project1".categories as C
where (O.order_id = OD.order_id )
and (P.product_id = OD.product_id)
and (C.category_id = P.category_id)
and (shipped_date > '1997-6-1')
group by category_name,shippedyear
)

select shippedyear,
category_name,
sum(categorysales)
from x 
group by shippedyear,category_name
order by shippedyear''')	
rows = cursor.fetchall()
print('shippedyear\t category_name\t\t sum')
for row in rows:
    print(str(row[0]).ljust(10) + " \t " + str(row[1]).ljust(20)+ " \t " + str(row[2]) )

connection.commit()
connection.close()