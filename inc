
    <!-- Contact us start from herr-->

    <div class="bg-secondary" id="contact-section">

        <div class="container">
            <div class="row ">
                <div class="col-md-5 quick-links">

                    <h2 class="quick-links-title">Quick Links: </h2>

                    <ul>
                        <li> <i class="fas fa-chevron-right"></i> <a class="quick-link-item" href="index.php"> Home</a> </li>
                        <li> <i class="fas fa-chevron-right"></i> <a class="quick-link-item" href="course.php">Cources</a> </li>
                        <li> <i class="fas fa-chevron-right"></i> <a class="quick-link-item" href="aboutus.php"> About</a> </li>

                    </ul>

                </div>
                <div class="col-md-2"></div>

                <div class="col-md-5 contact-form">
                    <h5 class="service-card-title">Stay Connected </h5>
                    <div class="tf-one">
                        <table>
                            <tr>
                                <td class="footer-td"><i class="fas fa-map-marker-alt"></i></td>
                                <td class="footer-td2">Mirpur City, Dhaka</td>
                                
                            </tr>
                            <tr>
                                <td class="footer-td"><i class="fas fa-phone-volume"></i></td>
                                <td class="footer-td2">+880900000</td>
                            </tr>
                            <tr>
                                <td class="footer-td"><i class="fas fa-envelope"></i></td>
                                <td class="footer-td2"> kidslearning@gmail.com</td>
                            </tr>
                        </table>
                    </div>
                </div>

            </div>
        </div>
    </div>

    <!-- Contact us end here -->

    <!-- Footer Section Start from here  -->
    <div class="copyright">
        <p class="copyright_text"> &copy; All Right Reserved by: Creative Web Hunter | 2021-2022</p>
    </div>

    <!-- Footer section end here  -->

    <!-- JavaScript Source File -->

    <script src="js/bootstrap.min.js"></script>
    <script src="js/script.js"></script>
</body>

</html>
<?php 
    include('lib/Session.php');
    Session::init();
    include 'lib/Database.php'; 
    include 'classes/course.php';
    include 'classes/User.php';
    include 'classes/Contact.php';
    include 'classes/exam.php';
    include 'classes/Process.php';
?>
<?php
    $db  = new Database();
    $cr  = new course();
    $us  = new User();
    $con = new Contact();
    $exm = new Exam();
    $pro = new Process();
    
?>


<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge" />
    <meta name="viewport" content="width=device-width, initial-scale=1.0" />
    <title>Kids Smart Learning: A Smart Way To Teach Our Kids</title>
    <!-- ?favicon icon -->
    <link rel="shortcut icon" href="images/page-1/logo.png" type="image/png">
    <!-- bootstrap offline framrwork -->
    <link rel="stylesheet" href="css/bootstrap.min.css" />
    <!-- custom css file link -->
    <link rel="stylesheet" href="css/style.css" />
    <link rel="stylesheet" href="css/aboutstyle.css" />
    <link rel="stylesheet" href="css/okkhorstyle.css" />
    <link rel="stylesheet" href="css/reesponsive.css">
    <!-- font awesome cdn link -->
    <link rel="stylesheet" href="https://use.fontawesome.com/releases/v5.15.4/css/all.css" integrity="sha384-DyZ88mC6Up2uqS4h/KRgHuoeGwBcD4Ng9SiP4dIRy0EXTlnuz47vAwmeGwVChigm" crossorigin="anonymous">
    <!-- bootstrap online framrwork -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>

</head>

<?php
    if (isset($_GET['uid'])){
        Session::destroy();
    }
?>



<body>
    <!-- Navigation part start from here -->
    <nav class="navbar nav-before navbar-expand-lg navbar-light bg-light menu-shadow">
        <a class="navbar-brand" href="index.php"><img class="nav-logo" id="logo-image" src="images/page-1/logo.png"></a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarTogglerDemo02"
            aria-controls="navbarTogglerDemo02" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>

        <div class="collapse navbar-collapse" id="navbarTogglerDemo02">
            <ul class="navbar-nav mr-auto mt-3 mt-lg-0">
                <li class="nav-item active">
                    <a class="nav-link nav-font" href="index.php">Home </a>
                </li>
                <li class="nav-item">
                    <a class="nav-link nav-font" href="course.php">Courses </a>
                </li>
                <li class="nav-item">
                    <a class="nav-link nav-font" href="aboutus.php">About </a>
                </li>

                <li class="nav-item">
                    <a class="nav-link nav-font" href="contact.php">Contact</a>
                </li>
            </ul>

            <?php 
                    $login = Session::get("userlogin");
                    if ($login == false) {
                       ?>
                     <form class="form-inline my-2 my-lg-0">
                        <a href="signIn.php"class="normal-btn btn">Sign In</a>
                    </form>
                       <?php
                    }else{
                        ?>
                                <?php
                                        $id =  Session::get("uid");
                                        $getdata = $us->getUserData($id);
                                        if ($getdata) {
                                            while($result = $getdata->fetch_assoc()){

                                    ?>

                         <form class="form-inline my-2 my-lg-0 ">
                             <div class="text-center mr-4">
                                 <a href="profile.php" style="text-decoration:none;color:#000">
                                 <img src="<?php echo $result['userImage']; ?>" class="header-profile-img" style="border-radius:50%; height:50px; width:50px;" alt=""><br>
                            <p class="m-0"><?php echo $result['userName']; ?></p></a>
                             </div>

                             <?php } } ?>
                         
                        </form>
                        <form class="form-inline my-2 my-lg-0">
                        <a href="?uid=<?php Session::get('uid'); ?>" class="btn btn-danger">Sign Out</a>
                        </form>
                        <?php
                    }
                ?>


           
        </div>
    </nav>

    <!-- Navigation part end here  -->
 <!-- Carousel part start from here  -->

 <div id="demo" class="carousel slide" data-ride="carousel">

<!-- Indicators -->
<ul class="carousel-indicators">
    <li data-target="#demo" data-slide-to="0" class="active"></li>
    <li data-target="#demo" data-slide-to="1"></li>
    <li data-target="#demo" data-slide-to="2"></li>
</ul>

<!-- The slideshow -->
<div class="carousel-inner">
    <div class="carousel-item active">
        <img src="images/page-1/backgroung-1.png" alt="">
    </div>
    <div class="carousel-item">
        <img src="images/page-1/backgroung-2.png" alt="">
    </div>
    <div class="carousel-item">
        <img src="images/page-1/backgroung-3.png" alt="">
    </div>
</div>

<!-- Left and right controls -->
<a class="carousel-control-prev" href="#demo" data-slide="prev">
    <span class="carousel-control-prev-icon"></span>
</a>
<a class="carousel-control-next" href="#demo" data-slide="next">
    <span class="carousel-control-next-icon"></span>
</a>
</div>

<!-- Carousel part end here -->
