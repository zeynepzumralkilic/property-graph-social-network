from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route("/query", methods=["POST"])
def query():

    text = request.json["query"].lower()

    if "friend" in text:
        return jsonify({
            "action":"FRIENDS",
            "user":1
        })

    if "photo" in text:
        return jsonify({
            "action":"PHOTOS",
            "user":1
        })

    return jsonify({
        "action":"UNKNOWN"
    })

app.run(host="0.0.0.0", port=5001)