puts "Enter a number: "

n = gets.to_i

f=1

i=1

while i<=n do

	f = f*i

	i= i+1

end

puts "factorial of #{n} is #{f}"
