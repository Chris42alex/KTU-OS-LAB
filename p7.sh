while true; do
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Exit"
    echo "Enter the option"
    read op
    
    if [ "$op" -eq 5 ]; then
        echo "Exiting..."
        break
    fi
    
    echo "Enter 2 numbers"
    read a
    read b
    
    case $op in
        1) r=$(($a + $b))
           echo "Result: $r";;
        2) r=$(($a - $b))
           echo "Result: $r";;
        3) r=$(($a * $b))
           echo "Result: $r";;
        4) r=$(($a / $b))
           echo "Result: $r";;
        *) echo "INVALID option";;
    esac
done

