<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" lang="fr">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<title>Pink Pony Monitoring - Oakley</title>	
	<link rel="icon" type="image/gif" href="images/favicon.ico" />
	<link href="<?php echo base_url('assets/css/main.css'); ?>" rel="stylesheet" type="text/css" />
	<script src="http://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap-theme.min.css">
	<link href='http://fonts.googleapis.com/css?family=Pacifico' rel='stylesheet' type='text/css'>
	<link href='http://fonts.googleapis.com/css?family=Oswald:400,700' rel='stylesheet' type='text/css'>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/js/bootstrap.min.js"></script>
</head>
<body>
	<input type="hidden" id="view" value="<?php echo $view; ?>">
	<input type="hidden" id="token" value="<?php echo $token; ?>">
<div id="header">
	<nav class="navbar navbar-default" role="navigation">
		<div id="container-fluid">
			<div id="navbar-header">
				<a class="navbar-brand" href="#">Pink Pony Monitoring</a>
			</div>
		</div>
	    <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
		    <ul class="nav navbar-nav">
		    	<li class="active"><a href="<?php echo site_url(''); ?>">Tableau de bord</a></li>
		    	<li><a href="<?php echo site_url('home/admin'); ?>">Administration</a></li>
		    </ul>
	    </div>
	</nav>
</div>
<div id="dash">
	<div id="dash-1">
		<div id="dash-content-serveur" class="content-detail">
			<div class="title-server-detail"><?php echo $client->name; ?></div>
			<div class="data-ok-detail">OK</div>
		</div>
		<?php $i = 1; 
		foreach ($track as $t) { 
			if ($i == 7)
				$i = 1;
		?>

		<div id="dash-content-data<?php echo $i; ?>" class="content-detail">
			<div class="title-detail"><?php echo $t->type; ?></div>
			<div class="data-detail"><span <?php echo 'id="val-'.$t->server_key.'-'.str_replace(".", "-", $t->type).'"'; ?>></span></div>
		</div>
		<?php $i++; } ?>
		<!-- <div id="Return-board" class="content-detail"><a href="#">Retourner au tableau de bord</a></div> -->
	</div>
</div>
<script type="text/javascript">
	function set_new_val()
	{
		$.ajax({
		type: 'GET',
            url: '<?php echo site_url("home/get_tracker")."/".$client->key;?>',
            dataType: 'json',
            success: function(response) {
            	$.each (response, function (bb) {
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
            	var view = $('#view').val();
            	var token = $('#token').val();
            	if (response.ret != view)
            	{
            		console.log("val modif");
            		if (response.ret == '0')
            			window.location.href = "http://77.194.204.33:11080/PPM/";
            		else 
            			window.location.href = "http://77.194.204.33:11080/PPM/index.php/home/view/"+token+'/'+response.ret;
            	}
            }
	});
	}

	setInterval(check_view, 200);
	setInterval(set_new_val, 2000);
</script>
</body>
</html>