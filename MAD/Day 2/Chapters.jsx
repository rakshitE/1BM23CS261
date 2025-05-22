// components/CourseView/Chapters.jsx

//Timestamp - 3:13:00 (add doc in firebase)
//modify addCourse/index.jsx

import { View, Text, Image, Pressable, Touchable, TouchableOpacity, StyleSheet } from 'react-native' 
import React from 'react'
import { imageAssets } from '../../constant/Option'
import { Ionicons } from '@expo/vector-icons'
import Button from './../../components/Shared/Button'

export default function Chapters({ course }) {
    const router = useRouter();

    const isChapterCompleted = (index) => {
        const isCompleted = course?.completedChapter.find(item => item==index)
        return isCompleted?true:false
    }
    return (
        <View style = {{
            padding: 20
        }}>
            <Text style = {{
                fontFamily: 'outfit-bold',
                fontSize: 25
            }}>Chapters</Text>

            <FlatList
                data = {course?.chapters}
                renderItems = {({ item, index}) => (
                    <TouchableOpacity onPress = {()=>{
                        router.push({
                            pathname: '/chapterView',
                            params:{
                                chapterParams: JSON.stringify(item),
                                docId: course?.docId,
                                chapterIndex: index
                            }
                        })
                    }} style = {{
                        padding: 18,
                        borderWidth: 0.5,
                        borderRadius: 15,
                        marginTop: 10,
                        display: 'flex',
                        flexDirection: 'row',
                        justifyContent: 'space-between',
                        alignItems: 'center'
                    }}>
                        <View style = {{
                            display: 'flex',
                            flexDirection: 'row',
                            gap: 10,
                        }}>
                            <Text style = {styles.chapterText}>{index + 1}.</Text>
                            <Text style = {styles.chapterText}>{item?.chapterName}</Text>
                        </View>
                        {isChapterCompleted(index)?
                            <Ionicons name="checkmark-circle" size={24} color={Colors.GREEN} />
                            :<Ionicons name="play" size={24} color={Colors.PRIMARY} />}
                    </TouchableOpacity>
                )}
            />
        </View>
    )
}

const styles = StyleSheet.create({
    chapterText: (
        fontFamily: 'outfit-bold',
        fontSize: 20
    )
})