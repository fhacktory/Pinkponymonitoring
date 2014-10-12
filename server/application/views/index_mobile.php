<!DOCTYPE html>
<html>
<head>
	<title>Appart</title>
	<link rel="stylesheet" type="text/css" href="<?php echo base_url('assets/css/style.css'); ?>">
	<meta http-equiv="content-type" content="text/html; charset=utf-8" />
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap-theme.min.css">
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/js/bootstrap.min.js"></script>
	<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8/jquery.min.js"></script>
</head>
<body class="remote">
	<?php if ($aut != 0) {?> 
	<h1>Remote Control</h1>
	<ul class="server">

		<?php
		$i = 1;
		foreach ($server as $s) { ?>
		<li onclick="myErase1('f26cc976eac8f684f0f3be3a6fd629b9', <?php echo $i; ?>)" ><span><?php echo $s->name; ?></span></li>
		<?php
		$i++; 
		}
		?>
		<li onclick="myErase1('f26cc976eac8f684f0f3be3a6fd629b9', 0)"><span>Home</span></li> 
	</ul>
	<?php } ?>
</body>
<script type="text/javascript">
function myErase1(token, view) {
	$.ajax({
		type: 'GET',
            url: '<?php echo site_url("home/change_view");?>/' + token + '/' + view, 
            dataType: 'json',
            success: function(response) {
            	console.log(response.ret);
            }
	});
}
</script>
</html>
	
<!-- 	<input type="submit" value="view1" class="sub" id="sub" onclick="myErase1('f26cc976eac8f684f0f3be3a6fd629b9', 1)">
	<input type="submit" value="view2" class="sub" id="sub" onclick="myErase1('f26cc976eac8f684f0f3be3a6fd629b9', 2)">
	<input type="submit" value="view3" class="sub" id="sub" onclick="myErase1('f26cc976eac8f684f0f3be3a6fd629b9', 3)">
	<input type="submit" value="view4" class="sub" id="sub" onclick="myErase1('f26cc976eac8f684f0f3be3a6fd629b9', 4)">
	<input type="submit" value="Home" class="sub" id="sub" onclick="myErase1('f26cc976eac8f684f0f3be3a6fd629b9', 0)">
</body> -->




