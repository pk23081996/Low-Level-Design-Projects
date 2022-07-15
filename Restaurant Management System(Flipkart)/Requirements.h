#ifndef REQUIREMENTS_H
#define REQUIREMENTS_H

/*
Machine Coding: Food ordering system

Description
Implement an online food ordering system the details of

All restaurants have menus that list all the items alongside their price.
Users are shown a list of all items available on the system.
Users can select multiple items from this list and proceed to ordering.
An order is deliverable if all the items in the order can be fulfilled by at least one restaurant.
Each restaurant has a maximum processing capacity. Beyond that, it won’t accept any further item requests until items that are being processed are dispatched.
Each restaurant takes some time to prepare and dispatch food. Once the item is dispatched the processing capacity reservation for the item is released.

Requirements
Restaurants should be able to register themselves on the system.
Restaurants should be able to update their menu.
Restaurants should be able to update the order status.
Customers should be able to place an order by giving multiple items and quantity details. Ignore cart management and payment processing for simplicity.
Restaurants should not breach their processing capacity.

Bonus
Attempt this only after completing the above requirements.

Customers can assign an optionality to an item, i.e. some items in the order can be marked as optional. Thus if the order cannot be fulfilled for all the items, a subset of the order can be delivered.
In case multiple restaurants are offering the same item, select the one which is offering the lowest cost.
The restaurant selection strategy should be configurable. Thus there could be a strategy that selects a restaurant that is offering an item at a lower cost and another one could select a restaurant with a higher rating.
Handle concurrency in the code. Make it so that any code path is callable from multiple threads without causing issues such as race conditions.

Expectations and guidelines
You are allowed to access the internet.
You are free to use any language of your choice.
Do not use any external libraries. All of the code should be your own.
Implement the code using only in-memory data structures or basic file handling. The use of databases is not allowed.
Create the sample data yourself. You can put it into a file, test cases or the main driver program itself.
Your code should be demo-able either through a main driver program or test cases. Code that does not run will not be evaluated.
Code should be modular and have the correct abstractions.
Code should be extensible. Wherever applicable, use interfaces and contracts between different methods. It should be easy to add/remove functionality without re­writing the entire codebase.
Code should handle edge cases properly and fail gracefully.
Code should be legible, readable, and DRY.
Code should be testable.
Please focus on the Bonus requirement only after ensuring the required features are complete and demoable. The bonus portion would not be evaluated if any of the required functionality is missing.
After completing the code upload it to the google drive folder shared by the interviewer.

Test Cases
Sample test cases:

This is for illustration purposes only.
You can define your ways to take input.
You can use driver class or take input from console or you can write UT’s
1. Onboard Restaurants

● R1
“max_orders_that_can_be_processed_at_a_time” : 5, “Menu”: [Veg Biryani : Rs.100, Chicken Biryani: Rs.150],
“rating”: 4.5/5

● R2
“max_orders_that_can_be_processed_at_a_time”: 5,
menu: [Chicken Biryani : Rs.175, Idli : Rs.10, Dosa : Rs.50, Veg Biryani : Rs. 80],
rating: 4/5

● R3
“max_orders_that_can_be_processed_at_a_time”: 1,
menu: [Gobi Manchurian : Rs.150, Idli : Rs.15, Chicken Biryani : Rs.175, Dosa: Rs.30 ],
rating: 4.9/5

2. Update restaurant menu
● ADD: {Restaurant_1, add, Chicken65, Rs.250}
● UPDATE: {Restaurant_2, update, Chicken Biryani, Rs.150}

3. Place Order
Order1
Input: { user: Ashwin, items: [ 3*Idli, 1*Dosa ], selection: Lowest cost }
Output: Order assigned to R3

Order2.
Input: { user: Harish, items: [ 3*Idli, 1*Dosa ], selection: Lowest cost }
Output: Order assigned to R2 (Not R3 since it has reached its full capacity from Order1)

Order3:
Input: { user: Shruthi, items: [3*Veg Biryani], selection: ‘Highest rating’ }
Output: Order assigned to R1

4. Update Order Status:
R3 marks Order1 as COMPLETED Order4:
Input: { user: Harish, items: [ 3*Idli, 1*Dosa ], selection: Lowest cost }
Output: Order assigned to R3 (since R3 has COMPLETED Order1)

Order5:
Input: {user: xyz, items: [1*Paneer Tikka, 1*Idli], selection: ‘Lowest cost}
Output: Order can’t be fulfilled (since none of the restaurants above serve Paneer Tikka)

*/

#endif // REQUIREMENTS_H
