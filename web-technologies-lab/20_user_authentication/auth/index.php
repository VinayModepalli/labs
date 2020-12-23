<!doctype html>
<?php
if (!isset($_COOKIE["login"])) // $_COOKIE is a variable and login is a cookie name 
    header("location:login.php");
?>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">

    <title>Hello, world!</title>
</head>

<body>
    <!--
    <h1>Hello, world!</h1>
    <div class="md:container md:mx-auto">
        
        <h1>Hey ! welcome to main page .</h1>

        <a href="page1.php">
            <h2>
                <font color="">PAGE 1</font>
            </h2>
        </a>
        <a href="page2.php">
            <h2>
                <font color="">PAGE 2</font>
            </h2>
        </a>
        <a href="page3.php">
            <h2>
                <font color="">PAGE 3</font>
            </h2>
        </a>
        <a href="logout.php">
            <h2>
                <font color="red">Logout</font>
            </h2>
        </a>
    </div>
    -->
    <div class="md:container md:mx-auto">
    <h1>
        <?php
        $cookie_name = "login";
            if(isset($_COOKIE[$cookie_name])) {
                echo "Hey " . $_COOKIE[$cookie_name]. ", welcome to my website";
                } else {
                    echo "Hey User, welcome to my website";
            }
        ?>
    </h1>
    <!--<h1>Hey Vinay, Welcome to my Website..!</h1>-->
    <a href="logout.php">   
        <h2>Log Me Out</h2>
    </a>
    </div>
    
    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
</body>

</html>