extends CanvasLayer


# Called when the node enters the scene tree for the first time.
func _ready():
	$Message.hide()


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass


func show_message(text):
	$Message.text = text
	$Message.show()
	$MessageTimer.start()

func stopTimer():
	$MessageTimer.stop()
	$Message.hide()

func _on_message_timer_timeout():
	$Message.hide()


func _on_player_hit():
	show_message("YOU DIED")
