<?php 
if(isset($_COOKIE["login"]))
	header("location:index.php");
?>

<!doctype html>
<html lang="en">

<head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css" integrity="sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm" crossorigin="anonymous">
    <link rel="stylesheet" href="style.css">
    <title>Login</title>
</head>

<body>
    <div class="global-container">
        <div class="card login-form">
            <div class="card-body">
                <h3 class="card-title text-center">Log in</h3>
                <div class="card-text">
                    <!--
			<div class="alert alert-danger alert-dismissible fade show" role="alert">Incorrect username or password.</div> -->
                    <form action="makelogin.php" method="POST">
                        <!-- to error: add class "has-danger" -->
                        <div class="form-group">
                            <label>Username</label>
                            <input type="text" class="form-control form-control-sm" required="" name="uname">
                        </div>
                        <div class="form-group">
                            <label>Password</label>
                            <a href="#" style="float:right;font-size:12px;">Forgot password?</a>
                            <input type="password" class="form-control form-control-sm" required="" name="upassword">
                        </div>
                        <div class="form-group">
                            <input type="checkbox" value="1" name="remember">keep me login
                        </div>
                        <button type="submit" class="btn btn-primary btn-block" value="Login" name="sub">Sign in</button>

                        <div class="sign-up">
                            Don't have an account? <a href="signup.php">Create One</a>
                        </div>
                        <!--phpcode-->
                        <?php
                        if (isset($_REQUEST["err"]))
                            $msg = "Invalid username or Password";
                        ?>
                        <p style="color:red;">
                            <?php if (isset($msg)) {

                                echo $msg;
                            }
                            ?>
                        </p>
                        <!--end of phpcode-->
                    </form>
                </div>
            </div>
        </div>
    </div>


    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/js/bootstrap.min.js" integrity="sha384-JZR6Spejh4U02d8jOt6vLEHfe/JQGiRRSQQxSfFWpi1MquVdAyjUar5+76PVCmYl" crossorigin="anonymous"></script>
</body>

</html>