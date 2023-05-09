echo "Enter the number whose factorial is to be found"
read num

fact=1

while [ $num -gt 1 ]
do
  fact=$((fact * num)) 
  num=$((num - 1))      
done

echo $fact
