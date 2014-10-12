<!DOCTYPE html>
<html>
<head>
	<title>Pink Pony Monitoring</title>
	<meta http-equiv="content-type" content="text/html; charset=utf-8" />
	<link rel="icon" type="image/gif" href="images/favicon.ico" />
	<!-- Latest compiled and minified CSS -->
	<link rel="stylesheet" type="text/css" href="<?php echo base_url('assets/css/main.css'); ?>">
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">
	<!-- Optional theme -->
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap-theme.min.css">
	<!-- Latest compiled and minified JavaScript -->
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/js/bootstrap.min.js"></script>
	<script type="text/javascript" src="http://ajax.googleapis.com/ajax/libs/jquery/1.8/jquery.min.js"></script>
	<link href='http://fonts.googleapis.com/css?family=Pacifico' rel='stylesheet' type='text/css'>
	<link href='http://fonts.googleapis.com/css?family=Oswald:400,700' rel='stylesheet' type='text/css'>
</head>
<body>
<div id="header">
	<nav class="navbar navbar-default" role="navigation">
		<div id="container-fluid">
			<div id="navbar-header">
				<a class="navbar-brand" href="<?php echo site_url(''); ?>">Pink Pony Monitoring</a>
			</div>
		</div>
	    <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
		    <ul class="nav navbar-nav">
		    	<li class="active"><a href="#">Tableau de bord</a></li>
		    	<li><a href="<?php echo site_url('home/admin'); ?>">Administration</a></li>
		    </ul>
	    </div>
	</nav>
</div>
<div id="dash">
<?php 
$j = 1;
foreach ($client as $c) { ?>

	<?php if ($j % 2 == 0) {?>
	<div id="dash-4-right">
	<?php } else { ?>
	<div id="dash-4">
	<?php } ?>
		<div id="dash-content-serveur" class="content">
			<div class="title"><?php echo $c->name; ?></div>
			<div class="data-ok">OK</div>
		</div>

		<?php 
			$tracker = file_get_contents(site_url("home/get_tracker/".$c->key));
			$tracker = json_decode($tracker);
			$i = 1;
			foreach ($tracker as $t) {
				if ($i < 6) {
		?>
			<div id="dash-content-data<?php echo $i; ?>" class="content">
			<div class="title"><span <?php echo 'id="til-'.$t->server_key.'-'.str_replace(".", "-", $t->type).'"'; ?>><?php echo $t->type; ?></span></div>
			<div class="data"><span <?php echo 'id="val-'.$t->server_key.'-'.str_replace(".", "-", $t->type).'"'; ?>></span></div>
		</div>
		<?php 
		} 
		$i++; ?>
		<?php } ?>
	</div>
<?php $j++; } ?>	
</div>
<center>
	<?php $remote = urlencode('http://77.194.204.33:11080/PPM/index.php/home/index_mobile/'.$token.''); ?>
	<img style="margin: 2%;" src="https://api.qrserver.com/v1/create-qr-code/?data=<?php echo $remote; ?>&size=150x150" alt="" title="" />
</center>

	<?php $token = "f26cc976eac8f684f0f3be3a6fd629b9" ?>
</body>
<script type="text/javascript">
	function set_new_val()
	{
		$.ajax({
		type: 'POST',
            url: '<?php echo site_url("home/get_all_val");?>',
            dataType: 'json',
            success: function(response) {
            	$.each (response, function (bb) {
				    console.log (response[bb].value);
				    console.log('val-'+response[bb].server_key+'-'+response[bb].type.replace('.', '-'));
				    $('#val-'+response[bb].server_key+'-'+response[bb].type.replace('.', '-')).text(response[bb].value.replace('-', '/').replace('_', ' '));
				});
            }
		});
	}

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
	setInterval(check_view, 200);
	setInterval(set_new_val, 2000);
	
</script>
</html>