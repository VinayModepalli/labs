<?php
include_once 'db.php';
if(isset($_POST['submit']))
{    
     $name = $_POST['name'];
     $email = $_POST['email'];
     $company = $_POST['company'];
     $message = $_POST['message'];
 
     $sql = "INSERT INTO users (name,email,company,message)
     VALUES ('$name','$email','$company','$message')";
 
     if (mysqli_query($conn, $sql)) {
        echo "New record has been added successfully !";
     } else {
        echo "Error: " . $sql . ":-" . mysqli_error($conn);
     }
     mysqli_close($conn);
}
?>