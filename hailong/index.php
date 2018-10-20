<?php
$first = new DateTime('2016-5-17 00:00:00', new DateTimeZone('Asia/Shanghai'));
$date = new DateTime('NOW', new DateTimeZone('Asia/Shanghai'));
$diff = $first -> diff($date);
$hailong = new DateTime('0000-01-01', new DateTimeZone('Asia/Shanghai'));
$hailong -> add($diff);
//echo $hailong -> format('Y-m-d');
?>
<!DOCTYPE html>
<html>
<head>
	<meta charset="utf-8">
	<title>海龙纪年</title>
	<script src="//cdn.bootcss.com/jquery/2.2.3/jquery.min.js"></script>
	<link href="//cdn.bootcss.com/bootstrap/3.3.6/css/bootstrap.min.css" rel="stylesheet">
	<script src="//cdn.bootcss.com/bootstrap/3.3.6/js/bootstrap.min.js"></script>
	<link href="//cdn.bootcss.com/bootstrap-material-design/4.0.1/bootstrap-material-design.min.css" rel="stylesheet">
</head>
<body>
	<div class="container-fluid">
		<div class="">
			<div class="row">
				<div class="jumbotron">
					<p style="text-align: center; font-size: 40px;">现在是海龙纪年：</p>
					<p style="text-align: center; font-size: 60px;"><?php echo $hailong -> format('Y 年 m 月 d 日'); ?></p>
				</div>
			</div>
		</div>
	</div>
</body>
</html>