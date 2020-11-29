const Numpad = (props) => {
    const keys = ["1", "2", "3", "4", "5", "6", "7", "8", "9", "0"]

    return (
        <div className="numpad-container">
        {keys.map(key =>
            <button key={key} className="numpad" onClick={() => props.numpadOnClick({ key })}>{key}</button>
        )}
        </div>
    )
}

export default Numpad