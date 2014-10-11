<!DOCTYPE html>
<html>
<head>
	<title>Appart</title>
	<meta http-equiv="content-type" content="text/html; charset=utf-8" />
	<!-- Latest compiled and minified CSS -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">

	<!-- Optional theme -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap-theme.min.css">

	<!-- Latest compiled and minified JavaScript -->
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/js/bootstrap.min.js"></script>
	<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8/jquery.min.js"></script>
</head>
<body class="test">
	<h1>TEST REMOTE</h1>
	<h2>View <?php echo $view ?></h2>
	<input type="hidden" id="view" value="<?php echo $view; ?>">;
	<input type="hidden" id="token" value="<?php echo $token; ?>">;
</body>
<script type="text/javascript">
	function check_view()
	{
		$.ajax({
		type: 'POST',
            url: '<?php echo site_url("home/check_view");?>', 
            dataType: 'json',
            success: function(response) {
            	var view = $('#view').val();
            	var token = $('#token').val();
            	if (response.ret != view)
            	{
            		console.log("val modif");
            		if (response.ret == 0)
            		{
            			window.location.href = "http://77.194.204.33:11080/PPM/";
            		}
            		window.location.href = "http://77.194.204.33:11080/PPM/index.php/home/view/"+token+'/'+response.ret;
            	}
            }
	});
	}

	setInterval(check_view, 500);
</script>
</html>