creators = Hash.new;
creators = {
	"C"=>"Dennis Ritchie",
	"Python"=>"Guido Van Russon",
	"Java"=>"James Gosling"	};
size = creators.length;
puts "Size of Hash is : #{size}";
creators.each do |key,val|
	puts "#{key} invented by #{val}";
end