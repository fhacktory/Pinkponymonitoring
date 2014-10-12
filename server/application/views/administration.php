<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="fr" lang="fr">
<head>
	<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
	<title>Pink Pony Monitoring - Oakley</title>	
	<link rel="icon" type="image/gif" href="images/favicon.ico" />
	<link href="<?php echo base_url('assets/css/main.css'); ?>" rel="stylesheet" type="text/css" />
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">
	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap-theme.min.css">
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/js/bootstrap.min.js"></script>
	<link href='http://fonts.googleapis.com/css?family=Pacifico' rel='stylesheet' type='text/css'>
	<link href='http://fonts.googleapis.com/css?family=Oswald:400,700' rel='stylesheet' type='text/css'>
</head>
<body>
<div id="header">
	<nav class="navbar navbar-default" role="navigation">
		<div id="container-fluid">
			<div id="navbar-header">
				<a class="navbar-brand" href="#">Pink Pony Monitoring</a>
			</div>
		</div>
	    <div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
		    <ul class="nav navbar-nav">
		    	<li><a href="<?php echo site_url(); ?>">Tableau de bord</a></li>
		    	<li class="active"><a href="#">Administration</a></li>
		    </ul>
			<ul class="nav navbar-nav navbar-right">
				<li><div id="KEYAPI">KEY : 085A42</div></li>
			</ul>
	    </div>
	</nav>
</div>
<div id="Admin">
	<div id="New-Serveur">
		<div id="Title">Vous avez <?php echo $nb_serv_z ?> serveur(s) à confirmer :</div>
		<?php foreach ($serv_z as $s) { ?>
		<div id="New-Serveur-Content">
			<p id="New-Serveur-Text"><?php echo $s->name; ?></p>
			<a id="New-Serveur-Supr" href="<?php echo site_url('home/remove_server/'.$s->key) ?>"><span class="glyphicon glyphicon-remove"></span></a>
			<a id="New-Serveur-Add" href="<?php echo site_url('home/val_server/'.$s->key) ?>"><span class="glyphicon glyphicon-ok"></span></a>
		</div>
		<?php } ?>
	</div>
	<div id="Serveur">
		<div id="Serveur-Title"><?php echo $nb_serv; ?> Serveur(s)</div>
		<?php foreach ($serv as $s) { ?>
		<div id="Serveur-Content">
			<p id="Serveur-Name"><?php echo $s->host; ?> - <span id="Serveur-Name-Color"><?php echo $s->name; ?></span></p>
			<a id="Serveur-Supr" href="<?php echo site_url('home/remove_server/'.$s->key) ?>">Supprimer</a>
			<a id="Serveur-Edit" href="<?php echo site_url('home/edit/'.$s->key) ?>">Editer</a>
			<a id="Serveur-Hide" href="#">Cacher</a>
		</div>
		<?php } ?>
	</div>
	</div>
</div>
</body>
</html>