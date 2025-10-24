extends CharacterBody2D


@export var health = 3


const SPEED = 100.0
const JUMP_VELOCITY = -400.0
# 1=right, -1=left 
var direction = 1

# Get the gravity from the project settings to be synced with RigidBody nodes.
var gravity = ProjectSettings.get_setting("physics/2d/default_gravity")


func _physics_process(delta):
	$AnimatedSprite2D.play()
	
	velocity.x = SPEED
	
	# Add the gravity.
	if not is_on_floor():
		velocity.y += gravity * delta

	if not ($RayCast2D.is_colliding()):
		direction = direction * -1
		velocity.x = velocity.x * direction
		$RayCast2D.force_raycast_update()
	elif not ($RayCast2D2.is_colliding()):
		direction = direction * -1
		velocity.x = velocity.x * direction
		$RayCast2D2.force_raycast_update()
	else:
		velocity.x = velocity.x * direction
		$RayCast2D.force_raycast_update()
		$RayCast2D2.force_raycast_update()

	move_and_slide()
		
		
func _on_body_body_entered(body):
	
	
	if(body.get_name() == "Player"):
		# TODO change to hurt player
		body.respawn()



func _on_obj_detector_body_entered(body):
	if(body.get_name() == "Player"):
		# TODO change to hurt player
		body.respawn()
	
	# turns around when it hits anything except bullets
	if(not body.get_name() == "bullet"):
		direction = direction * -1
		velocity.x = velocity.x * direction
		if $obj_detector.rotation_degrees == 0:
			# flip $AnimatedSprite2D
			$obj_detector.rotation_degrees = 180
		else: 
			# flip $AnimatedSprite2D
			$obj_detector.rotation_degrees = 0


func _exit_tree():
	get_tree().current_scene.give_point.emit()

func _on_body_area_entered(area):
	if area.is_in_group("player_bullet"):
		health -= 1
		$flash.play("flash")
	if health == 0:
		queue_free()
