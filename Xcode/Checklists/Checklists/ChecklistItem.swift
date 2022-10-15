//
//  ChecklistItem.swift
//  Checklists
//
//  Created by 조예진 on 2018. 3. 29..
//  Copyright © 2018년 Mia Cho. All rights reserved.
//

import Foundation

class ChecklistItem: NSObject {
    
    var text = " "
    var checked = false
    
    
    func toggleChecked() {
        checked = !checked
    }
    
}
