echo "Enter the limit"
read n
x=0
y=1
for((i=0;i<=n;i++))
do
echo $x
sum=$(($x+$y))
x=$y
y=$sum
done

