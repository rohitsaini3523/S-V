<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Profile </title><!-- Bootstrap css -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet">
    <!-- js -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js"></script>

    <link rel="stylesheet" href="style.css">

</head>

<body>
    <?php
    // define variables and set to empty values
    $email = $pass = "";

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $email = test_input($_POST["femail"]);
        $pass = test_input($_POST["fpass"]);
    }
    else{
        header("Location: login.php");
    }

    function test_input($data)
    {
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }
    ?>
    <?php
    if ($email != "" && $pass != "") {
        $conn = new MySQLi('localhost', 'root', '', 'regestration_records');
        if ($conn == false) {
            die("Connection Failed: " . $conn->connect_error);
        }
        // echo "Connected Successfully";
        $query = "select * from records where email='$email' and password='$pass';";
        // echo $query;
        $result = mysqli_query($conn, $query);
        $row = mysqli_fetch_array($result, MYSQLI_ASSOC);
        if ($row == NULL) {
            echo '<script>alert("Not Found")</script>';
            header("Location: /lab4/login.php");
        } else {
            $name = $row["name"];
            $email = $row["email"];
            $phno = $row["phoneno"];
            $pass = $row["password"];
            $cpass = $row["confirm_password"];
            echo '<script>alert("Login Success")</script>';
            echo "Name:- $name<br>";
            echo "email:- $email<br>";
            echo "PhoneNo:- $phno";
        }
    }
    ?>
    <center>
        <div class="container" style="padding: 15%;">
            <h1 style="font-family:'Lucida Sans', 'Lucida Sans Regular', 'Lucida Grande', 'Lucida Sans Unicode', Geneva, Verdana, sans-serif" id="username"></h1>
            <button type="button" class="btn" style="background-color:yellow;"><a href="update.php" style="text-decoration:none;color:red;">Update</a></button>
            <button type="button" class="btn" style="background-color:lightblue;"><a href="delete.php" style="text-decoration:none;color:black;">Delete</a></button>
            <button type="button" class="btn" style="background-color:red;"><a href="index.php" style="text-decoration:none;color:white;">Logout</a></button>
        </div>
    </center>
    <script src="algo.js">
    </script>
</body>

</html>