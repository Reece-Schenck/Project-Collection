extends CharacterBody2D


func _physics_process(delta):
	$AnimatedSprite2D.play()

func _on_body_body_entered(body):
	if(body.get_name() == "Player"):
		body.respawn()
