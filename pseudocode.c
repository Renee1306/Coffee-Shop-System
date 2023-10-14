
    READ cusid1
    LOOP i FROM 0 TO i < count STEP 1
    IF(string comparison between cusid1and acc[i].cusid == 0) THEN
    PRINT “Welcome!”, acc[i].name
    PRINT “Below is the menu”
    CALL show()
    PRINT “Enter item code”
    READ itemcode
    LOOP k FROM 0 TO k < count STEP 1
    IF(string comparison between itemcode and or [k].code == 0) THEN
    PRINT “Here are the details of item”
    PRINT “================================“
    PRINT “Item Code : ”, or [k].code
    PRINT “Item Price RM : ”, or [k].price
    PRINT “Item Name : ”, or [k].name
    PRINT “Enter quantity : ”
    READ ord[l].quantity
    ord[l].price = or [k].price * ord[l].quantity
    PRINT “ * ********************************”
    PRINT “Total Price  RM”, ord[l].price
    PRINT “ * ********************************”
    PRINT “Do you want to place order ? ”
    PRINT “[1] Yes”
    PRINT “[2] No”
    PRINT “---------------------------- - ”
    PRINT “Enter choice : ”
    READ choice
    CASE choice OF
    CASE 1
    here :
    PRINT “ * **************************”
    PRINT “Please select payment method * ”
    PRINT “[1] Cash”
    PRINT “[2] Ewallet”
    PRINT “[3] Credit cards”
    PRINT “[4] Online Banking”
    PRINT “ * ***********************”
    PRINT “Enter choice : ”
    READ choice1
    CASE choice1 OF
    CASE 1
    STRINGCOPY(ord[l].paymentmethod, “Cash”)
    BREAK
    CASE 2
    STRINGCOPY(ord[l].paymentmethod, “Ewallet”)
    BREAK
    CASE 3
    STRINGCOPY(ord[l].paymentmethod, “CreditCard”)
    BREAK
    CASE 4
    STRINGCOPY(ord[l].paymentmethod, “OnlineBanking”)
    BREAK
    DEFAULT
    PRINT “Invalid input.Please try again”
    GOTO here
    ENDCASE
    SET count = 0
    FILEOPEN customerorder.txt AS fp in READ mode
    IF(fp == NULL)  THEN
    PRINT “Error opening file.”
    RETURN 0
    ENDIF
    LOOP FROM c = getcfp TO c != EOF STEP c = getcfp
    IF(c == '') THEN
    count = count + 1
    ENDIF
    ENDLOOP
    FILECLOSE(fp)                    										ord[i].ordercode = count + 1
    PRINT “[Done payment by Customer Name, Customer ID]”, acc[i].name, acc[i].cusid
    PRINT “Order Date, tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900
    PRINT “Order Time % 02d % 02d % 02d”, tm.tm_hour, tm.tm_min, tm.tm_sec
    PRINT “ * **Your order code is # * **”, ord[l].ordercode
    PRINT “Thanks for visiting Dosta Coffee Shop”
    PRINT “Hope to see you again!”
    STRINGCOPY(ord[l].cusid, cusid1)
    STRINGCOPY(ord[l].cusname, acc[i].name)
    STRINGCOPY(ord[l].itemid, or [k].code)
    STRINGCOPY(ord[l].itemname, or [k].name)
    ord[l].year = tm.tm_year + 1900
    ord[l].month = tm.tm_mon + 1
    ord[l].day = tm.tm_mday
    ord[l].hour = tm.tm_hour
    ord[l].min = tm.tm_min
    ord[l].sec = tm.tm_sec
    SET l = 0
    FILEOPEN customerorder.txt AS fp in APPEND mode
    IF(fp1 == NULL) THEN
    PRINT “Error opening file”
    ELSE
    FILEPRINT ord[l].ordercode, ord[l].cusid, ord[l].cusname, ord[l].itemid, ord[l].itemname, ord[l].quantity, ord[l].price, ord[l].paymentmethod, ord[l].year, ord[l].month, ord[l].day, ord[l].hour, ord[l].min, ord[l].sec
    PRINT “[Data updated successfully in txt file!]”
    FILECLOSE(fp1)
    ENDIF
    PRINT “Do you want to CONTINUE orderingy / n ? ”
    GETCHAR()
    IF(getchar == 'y')
    PRINT “Directing back to order page.”
    CALL registeredorder()
    ELSE
    PRINT “Directing back to registered customer menu.”
    CALL registeredcusMenu()
    ENDIF
    CASE 2
    PRINTF “Ordered cancelled”
    PRINTF “Directing back to main menu”
    CALL registeredcusMenu();
BREAK;
DEFAULT:
PRINTF “Invalid operator. Please try again”
BREAK;
ENDCASE
IF(k == count) THEN
PRINT “Item Code not found !Please try again.”
CALL registeredorder()
ENDIF
IF(i == count) THEN
PRINT “Customer ID not found.Please try again”
CALL registeredorder()
ENDIF

2.1.24 Registered customer cancel order
FUCNTION registeredcancel
CALL readcusorder()
SET count = 100
SET codedel = 0
SET a, v
SET i = 0, j = 0
PRINT “----------------------------------------------------------------------”
PRINT “CANCEL ORDER PLACED”
PRINT “----------------------------------------------------------------------”
PRINT “Enter order code to delete:”
READ codedel
PRINT “Enter customer id : ”
READ cusdel
LOOP i FROM 0 TO i < count STEP 1
    IF(string comparison between ord[i].cusid and cusdel == 0 AND ord[i].ordercode == codedel)
    PRINT “Below are the order details”
    PRINT “Order Code : ”, ord[i].ordercode
    PRINT “Customer ID : ”, ord[i].cusid
    PRINT “Customer Name : ”, ord[i].cusname
    PRINT “Item ID : ”, ord[i].itemid
    PRINT “Item Name : ”, ord[i].itemname
    PRINT “Quantity : ”, ord[i].quantity
    PRINT “Total Price : ”, ord[i].price
    PRINT “Payment Method : ”, ord[i].paymentmethod
    PRINT “Date : ”, ord[i].year, ord[i].month, ord[i].day
    PRINT “Time : ”, ord[i].hour, ord[i].min, ord[i].sec
    PRINT “Do you want to cancel order ? ”
    PRINT “1.Confirm”
    PRINT “2.Cancel”
    PRINT “======================== = “
    PRINT “Enter choice : ”
    READ a
    IF(a == 1) THEN
    LOOP j = I TO j < count – 1 STEP 1
    ord[j] = ord[j + 1]
    PRINT “[Canceled Successfully!]”
    count--
    CALL save2()
    BREAK
    ELSE
    PRINT “Order is not deleted!”
    PRINT “Directing back...”
    BREAK
    ENDIF
    ENDIF
    ENDLOOP
    IF(i == count)
    PRINT “Order id or customer id can't be found.”
    PRINT “Do you want to CONTINUE ? ”
    PRINT “1.CONTINUE 2.Back”
    PRINT “Enter choice”
    READ v
    IF(v == 1) THEN
    CALL registeredcancel()
    ELSE
    CALL registeredcusMenu()
    ENDIF
    ENDIF

    2.1.25 Registered customer save file
    FUCNTION save2
    SET count = 0
    SET i = 0
    SET ret = 0
    FILEOPEN customerorder.txt AS fp in READ mode
    IF(fp == NULL) THEN
    PRINT “Error opening file.”
    RETURN 0
    ENDIF
    LOOP FROM for c = GETC(fp) TO c != EOF STEP c = getcfp
    IF(c == '') THEN
    count = count + 1
    ENDIF
    ENDLOOP
    FILECLOSE(fp)
    FILEOPEN customerorder.txt AS fp2 in WRITE mode
    IF(fp2 == NULL) THEN
    PRINT “Error opening file”
    ENDIF
    LOOP i FROM 0 TO i < count STEP 1
    ret = FILEPRINT ord[i].ordercode, ord[i].cusid, ord[i].cusname, ord[i].itemid, ord[i].itemname, ord[i].quantity, ord[i].price, ord[i].paymentmethod, ord[i].year, ord[i].month, ord[i].day, ord[i].hour, ord[i].min, ord[i].sec
    ENDLOOP
    IF(ret < 0) THEN
    PRINT “Error”
    ELSE
    PRINT “============Data updated successfully in txt file!===========”
    FILECLOSE(fp2)
    ENDIF

    2.1.26 Registered customer show receipt
    FUCNTION registeredreceipt
    SET l = 0
    CALL readcusorder()
    SET count = 100
    SET ordercode1 = 0
    SET password = 0
    PRINT “----------------------------------------------------------------------”
    PRINT “                      	SHOW RECEIPT”
    PRINT “----------------------------------------------------------------------”
    PRINT “Enter order ID : ”
    READ ordercode1
    PRINT “Enter customer ID : ”
    READ cusid1
    WHILE(l < count)
    IF(string comparison between ord[l].cusid and cusid1 == 0 AND ord[l].ordercode == ordercode1
        PRINT “_______________________________________________________”
        PRINT “                  	Dosta Coffee Shop, ”
        PRINT “                  	No.666, Jalan Bunga, ”
        PRINT “                  	34567 Kuala Lumpur”
        PRINT “------------------------------------------------------”
        PRINT “                       	RECEIPT                     	”
        PRINT “================================== = ”
        PRINT “Order Code : Date:”, ord[l].ordercode, ord[l].year, ord[l].month, ord[l].day
        PRINT “Customer ID : Time:”, ord[l].cusid, ord[l].hour, ord[l].min, ord[l].sec
        PRINT “Customer Name : Payment Method : ”, ord[l].cusname, ord[l].paymentmethod
        PRINT “================================== = ”
        PRINT “                                                     			      	”
        PRINT “  Name         	Quantity          	TotalRM     			”
        PRINT “------------------------------------------------------”
        PRINT “ ”, ord[l].itemname, ord[l].quantity, ord[l].price
        PRINT “    	                                                  			”
        PRINT “                                                           			”
        PRINT “                                                           			”
        PRINT “                                                           			”
        PRINT “                                                           			”
        PRINT “                                                           			”
        PRINT “  ========================================	”
        PRINT “    	Sub Total                  				”, ord[l].price
        PRINT “     ==================================== = ”
        PRINT “             		Thanks for visiting us           	     	”
        PRINT “              		Hope to see you again                	”
        PRINT “__________________________________________________”
        PRINT “Do you want to CONTINUE to PRINT receipty / n ? ”
        GETCHAR()
        IF(getchar == 'y')
        PRINT “Directing back...”
        CALL registeredreceipt()
        ELSE
        PRINT “Directing back to registered customer menu.”
        CALL registeredcusMenu()
        ENDIF
        ELSE
        l++
        ENDIF
        IF(string comparison between ord[l].cusid, cusid1 != 0 AND ord[l].ordercode != ordercode1)
        PRINT “Incorrect customer id or order code.Please try again”
        CALL registeredreceipt()
        ENDIF





