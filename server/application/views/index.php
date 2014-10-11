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
	<h2>View 0</h2>
	<?php $token = "f26cc976eac8f684f0f3be3a6fd629b9" ?>
</body>
<script type="text/javascript">
	function check_view()
	{
		$.ajax({
		type: 'POST',
            url: '<?php echo site_url("home/check_view");?>', 
            dataType: 'json',
            success: function(response) {
            	if (response.ret != 0)
            	{
            		console.log("val modif");
            		$(window).attr('location', "index.php/home/view/"+response.token+'/'+response.ret);
            	}
            }
	});
	}

	setInterval(check_view, 500);
</script>
</html>