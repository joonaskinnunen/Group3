import { useState } from 'react'

const Numpad = () => {
    const keys = [1, 2, 3, 4, 5, 6, 7, 8, 9]

    return (
        <div className="numpad-container">
        {keys.map(key =>
            <button key={key} className="numpad">{key}</button>
        )}
        </div>
    )
}

export default Numpad