extends CharacterBody2D

# signal squashed

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


func _on_top_body_entered(body):
	if(body.get_name() == "Player"):	
		queue_free() # Destroy this node


func _on_body_body_entered(body):
	if(body.get_name() == "Player"):
		body.respawn()

