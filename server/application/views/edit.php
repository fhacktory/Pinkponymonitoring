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
	<script src="http://ajax.googleapis.com/ajax/libs/jquery/1/jquery.min.js"></script>
	<link rel="stylesheet" href="<?php echo base_url('assets/css/vex-theme-default.css'); ?>" />
	<link href='http://fonts.googleapis.com/css?family=Pacifico' rel='stylesheet' type='text/css'>
	<link href='http://fonts.googleapis.com/css?family=Oswald:400,700' rel='stylesheet' type='text/css'>
	<script src="<?php echo base_url('assets/css/vex.combined.min.js'); ?>"></script>
	<script>vex.defaultOptions.className = 'vex-theme-os';</script>
	<link rel="stylesheet" href="<?php echo base_url('assets/css/vex.css'); ?>" />
	<link rel="stylesheet" href="<?php echo base_url('assets/css/vex-theme-os.css'); ?>" />
	<script type="text/javascript">
    	$(document).ready(function() {
    		$('#Edit-Sondes-1-desactiver').hide();
    		$('#Edit-Sondes-1').hover(function() {
    			$('#Edit-Sondes-1-desactiver').show();
    			// $('#Edit-Sondes-1').css({opacity: 0.5});
    			$('#Edit-Sondes-1').fadeTo(500,0.7);;
    		}, function() {
	    		$('#Edit-Sondes-1-desactiver').hide();
    			$('#Edit-Sondes-1').fadeTo(500,1);;
	    	});
    		$('#Edit-Sondes-Add').hover(function() {
    			$('#Edit-Sondes-Add').fadeTo(500,0.7);;
    		}, function() {
    			$('#Edit-Sondes-Add').fadeTo(500,1);;
	    	});
    		$('#Edit-Sondes-Add').click(function() {
    			vex.dialog.open({
			  		message: 'Ajouter une sonde :',
			  		// input: "<input name=\"\" type=\"text\" placeholder=\"Username\" required />\n<input name=\"password\" type=\"password\" placeholder=\"Password\" required />",
			  		input: "<select style='height:40px' name='track' id=\"sonde\" required>\n<option value=\"\">Selectionner un script</option>\n<?php foreach ($all_t as $a) { ?><option value=\"<?php echo $a->name; ?>\"><?php echo $a->name; ?></option>\n<?php } ?></select>\n<input type=\"hidden\" name=\"token\" value=\"<?php echo $client->key; ?>\">",
					buttons: [
				    	$.extend({}, vex.dialog.buttons.YES, {
			    	  		text: 'Ajouter'
			    			}), $.extend({}, vex.dialog.buttons.NO, {
					      	text: 'Annuler'
					    	})
					  	],
					  callback: function(data) {
					    if (data === false) {
					      return console.log('Cancelled');
					    }
					    return add_track(data.track, data.token);
					  }
					});
    		});
    		$('#Edit-Name-Change').hover(function() {
    			$('#Edit-Name-Change').fadeTo(500,0.7);;
    		}, function() {
    			$('#Edit-Name-Change').fadeTo(500,1);;
	    	});
    		$('#Edit-Name-Change').click(function() {
    			vex.dialog.open({
			  		message: 'Ajouter une sonde :',
			  		// input: "<input name=\"\" type=\"text\" placeholder=\"Username\" required />\n<input name=\"password\" type=\"password\" placeholder=\"Password\" required />",
			  		input: "<input name=\"nameserveur\" type=\"text\" placeholder=\"Nouveau nom du serveur\" required /><input type=\"hidden\" name=\"token\" value=\"<?php echo $client->key; ?>\">",
					buttons: [
				    	$.extend({}, vex.dialog.buttons.YES, {
			    	  		text: 'Valider'
			    			}), $.extend({}, vex.dialog.buttons.NO, {
					      	text: 'Annuler'
					    	})
					  	],
					  callback: function(data) {
					    if (data === false) {
					      return console.log('Cancelled');
					    }
					    return test_my(data.nameserveur, data.token);
					  }
					});
    			});
    		});
    </script>

    <script type="text/javascript">
    function test_my(name, token)
    {
    	$.ajax({
		type: 'GET',
            url: '<?php echo site_url("home/change_name");?>'+'/'+name+'/'+token,
            dataType: 'json',
            success: function(response) {
            	window.location.href = "http://77.194.204.33:11080/PPM/index.php/home/edit/"+token;
            }
		});
    }

    function add_track(track, token)
    {
    	$.ajax({
		type: 'GET',
            url: '<?php echo site_url("home/add_new_track");?>'+'/'+track+'/'+token,
            dataType: 'json',
            success: function(response) {
            	window.location.href = "http://77.194.204.33:11080/PPM/index.php/home/edit/"+token;
            }
		});
    }
    </script>
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
		    	<li class="active"><a href="<?php echo site_url('home/admin'); ?>">Administration</a></li>
		    </ul>
			<ul class="nav navbar-nav navbar-right">
				<li><div id="KEYAPI">KEY : 085A42</div></li>
			</ul>
	    </div>
	</nav>
</div>
<div id="Edit">
	<div id="Edit-Content">
		<div id="Edit-Info" class="content">
			<div id="Edit-Name"><?php echo $client->name; ?></div>
			<div id="Edit-Host"><?php echo $client->host; ?></div>
		</div>
		<div id="Edit-Name-Change" class="content">Changer le nom</div>
		<div id="Edit-Sondes" class="content-sondes"><?php echo $nb_track; ?> Sonde(s) activée(s)</div>		
		
		<?php 
		$i = 1;
		foreach ($track as $t) { ?>
		<div id="Edit-Sondes-<?php echo $i; ?>" class="content-sondes"><?php echo $t->type; ?></div>	
		<?php $i++;
		} ?>	
		<div id="Edit-Sondes-Add" class="content">Ajoutez une sonde</div>		
	</div>
</div>
</body>
</html>