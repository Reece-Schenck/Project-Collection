extends CharacterBody2D

signal hit

const SPEED = 300.0
const JUMP_VELOCITY = -400.0

# Get the gravity from the project settings to be synced with RigidBody nodes.
var gravity = ProjectSettings.get_setting("physics/2d/default_gravity")

var startX = 0
var startY = 0

func getStartLocationX():
	return position.x
	
func getStartLocationY():
	return position.y


func _physics_process(delta):
	if(startX == 0 and startY ==0):
		startX = getStartLocationX()
		startY = getStartLocationY()
		
	$AnimatedSprite2D.play()
	
	# Add the gravity.
	if not is_on_floor():
		velocity.y += gravity * delta

	# Handle jump.
	if (Input.is_action_just_pressed("jump") and is_on_floor() and $AnimatedSprite2D.animation != "crouch"):
		velocity.y = JUMP_VELOCITY
		$AnimatedSprite2D.animation = "jump"


	# Get the input direction and handle the movement/deceleration.
	# As good practice, you should replace UI actions with custom gameplay actions.
	var direction = Input.get_axis("move_left", "move_right")
	if direction:
		velocity.x = direction * SPEED
		
		if($AnimatedSprite2D.animation != "jump"):
			$AnimatedSprite2D.animation = "run"
			$AnimatedSprite2D.flip_v = false
			# See the note below about boolean assignment.
			$AnimatedSprite2D.flip_h = velocity.x < 0
		
	else:
		velocity.x = move_toward(velocity.x, 0, SPEED)
	
	if(velocity.x == 0 && velocity.y == 0):
		$AnimatedSprite2D.animation = "idle"
		
	if(Input.is_action_pressed("roll") && is_on_floor()):
		velocity.x = direction * (SPEED*2)
		$AnimatedSprite2D.animation = "roll"
		$AnimatedSprite2D.flip_v = false
		$AnimatedSprite2D.flip_h = velocity.x < 0


	move_and_slide()


func respawn():
	hit.emit()
	position.x = startX
	position.y = startY


func _on_hazard_body_entered(body):
	respawn()
